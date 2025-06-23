#include <vector>
#include <string>
#include <iostream>

#include "GameManager.h"

#include <iostream>
#include "../Types/Monster/Dragon.h"
#include "../Types/Monster/Goblin.h"
#include "../Types/Monster/Orc.h"
#include "../Types/Monster/Slime.h"
#include "../Types/Monster/Troll.h"
#include <random>

#include "../Types/Item/Item.h"
#include "../Types/Item/AttackBoost.h"
#include "../Types/Item/HealthPotion.h"
#include "../Console/ConsoleInput.h"

GameManager::GameManager()
{
	character == nullptr;
}

GameManager::~GameManager()
{
	if (character != nullptr) {
		delete character;
	}
}

void GameManager::CreateCharacter()
{
	// Temporal code
	character = new Character("임시", 100, 10);
	character->SetGold(100);
}

void GameManager::GenerateMonster(int characterLevel)
{
	//몬스터 생성
	monsters[0] = MonsterManager::CreateGoblin(characterLevel);
	monsters[1] = MonsterManager::CreateOrc(characterLevel);
	monsters[2] = MonsterManager::CreateSlime(characterLevel);
	monsters[3] = MonsterManager::CreateDragon(characterLevel);
	monsters[4] = MonsterManager::CreateTroll(characterLevel);
	
	std::random_device rd;         
	std::mt19937 gen(rd());        
	std::uniform_int_distribution<> monsterSizeRange(0, 3);

	monsterNum = monsterSizeRange(gen);

	if (characterLevel >= 10)
	{
		std::cout << "보스 몬스터 " << monsters[monsterNum]->GetName() << " 등장!";
	}
	else
	{
		std::cout << "몬스터 " << monsters[monsterNum]->GetName() << " 등장!";
	}

	std::cout << "체력:" << monsters[monsterNum]->GetHealth() << ",공격력:" << monsters[monsterNum]->GetAttack() << std::endl;
}

BattleResult GameManager::Battle()
{
	BattleResult result;
	result.isWin = false;
	result.isBoss = false;

	bool isMyTurn = true;
	bool isFighting = true;

	GenerateMonster(character->GetLevel());

	//전투중
	while(isFighting)
	{
		if (isMyTurn)
		{
			character->Attack(*monsters[monsterNum]);

			if (monsters[monsterNum]->GetHealth() <= 0)
			{
				isFighting = false;
			}
		}
		else
		{
			monsters[monsterNum]->Attack(*character);

			if (character->GetHealth() <= 0)
			{
				isFighting = false;
			}
		}

		isMyTurn = !isMyTurn;
	}

	if (character->GetHealth() > 0)
	{
		result.isWin = true;
	}

	if (character->GetLevel() >= 10)
	{
		result.isBoss = true;
	}

	for (Monster* monster : monsters)
	{
		delete monster;
		monster = nullptr;
	}

	return result;
}

const std::string GameManager::shopMessage = "";
const std::vector<std::string> GameManager::shopPrompt = {
	"물건 사기", "물건 팔기", "상점 나가기"
};

void GameManager::Shop()
{
	// options for print
	std::vector<std::string> buyOptions;
	std::vector<std::string> sellOptions;

	while (true) {
		int select = SelectNumber(shopPrompt);
		switch (select) {
		case 0: // Buy
			ShopBuy();
			break;
		case 1: // Sell
			if (character->GetInventory()->Count() > 0) {
				ShopSell();
			}
			else {
				// temp message
				std::cout << "판매할 물건이 없습니다." << std::endl;
			}
			break;
		case 2: // Exit 
			return;
		}
	}
}


void GameManager::ShopBuy()
{
	// Hardcoding..
	std::vector<Item*> shopItems;
	shopItems.push_back(new HealthPotion(50));
	shopItems.push_back(new AttackBoost(10));
	std::vector<int> prices;
	prices.push_back(shopItems[0]->GetPrice());
	prices.push_back(shopItems[1]->GetPrice());

	int gold = character->GetGold();

	// temp message
	std::cout << "소유 골드: " << character->GetGold() << std::endl;

	std::vector<std::string> options;
	for (int i = 0; i < shopItems.size(); i++) {
		options.emplace_back(shopItems[i]->GetName() + ", (" + std::to_string(prices[i]) + "골드)");
	}
	
	int buyIndex = SelectNumber(options);

	if (gold >= prices[buyIndex]) {
		gold -= prices[buyIndex];
		// TODO: refactoring...
		Item* newItem = nullptr;
		switch (buyIndex) {
		case 0:
			newItem = new HealthPotion(50);
			break;
		case 1:
			newItem = new AttackBoost(10);
			break;
		}
		if (newItem != nullptr) {
			character->GetInventory()->Insert(newItem);
			character->SetGold(gold);

			// temp message
			std::cout << newItem->GetName() << "을/를 구매했습니다. "
				<< "(남은 골드: " << gold << ")" << std::endl;
		}
	}
	else {
		// temp message
		std::cout << "골드가 모자랍니다" << std::endl;
	}
	
}

void GameManager::ShopSell()
{
	std::vector<Item*> items = character->GetInventory()->GetItems();

	std::vector<std::string> options;
	for (int i = 0; i < items.size(); i++) {
		options.emplace_back(items[i]->GetName());
	}

	int sellIndex = SelectNumber(options);

	// TODO: hard coding, refactoring, etc..
	Item* item = character->GetInventory()->Get(sellIndex);
	int price = item->GetPrice() * 60 / 100;
	// temp message
	std::cout << item->GetName() << "을/를 " << price << "골드에 팔았습니다." << std::endl;

	character->GetInventory()->Remove(sellIndex);
	character->SetGold(character->GetGold() + price);

	// temp message
	std::cout << "현재 소유 골드는 " << character->GetGold() << " 입니다." << std::endl;
}

