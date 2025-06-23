#include <vector>
#include <string>
#include <iostream>

#include "GameManager.h"

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
	// 상점에 방문했을 때, 사용하지 않는 모든 장비를 판매함
	ShopSellEquipment();

	while (true) {
		int select = SelectNumber(shopPrompt);
		switch (select) {
		case 0: 
			ShopBuyItem();
			break;
		case 1: 
			if (character->GetItemInventory()->Count() > 0) {
				ShopSellItem();
			}
			else {
				// temp message
				std::cout << "판매할 물건이 없습니다." << std::endl;
			}
			break;
		case 2: 
			return;
		}
	}
}

Item* GameManager::MakeShopItem(ShopItems index) {
	Item* shopItem = nullptr;
	int shop_healthRestore = 50;
	int shop_attackincrease = 4;
	switch (index) {
	case ShopHealthPotion:
		shopItem = new HealthPotion(shop_healthRestore);
		break;
	case ShopAttackBoost:
		shopItem = new AttackBoost(shop_attackincrease);
		break;
	default: 
		shopItem = nullptr;
		break;
	}
	return shopItem;
}

void GameManager::ShopBuyItem()
{
	std::vector<Item*> shopItems;
	shopItems.push_back(MakeShopItem(ShopItems::ShopHealthPotion));
	shopItems.push_back(MakeShopItem(ShopItems::ShopAttackBoost));

	int gold = character->GetGold();

	// temp message
	std::cout << "소유 골드: " << character->GetGold() << std::endl;

	std::vector<std::string> options;
	for (int i = 0; i < shopItems.size(); i++) {
		options.emplace_back(shopItems[i]->GetName() + ", (" + std::to_string(shopItems[i]->GetPrice()) + "골드)");
	}
	
	int buyIndex = SelectNumber(options);

	if (gold >= shopItems[buyIndex]->GetPrice()) {
		gold -= shopItems[buyIndex]->GetPrice();
		Item* newItem = nullptr;
		switch (buyIndex) {
		case 0:
			newItem = MakeShopItem(ShopItems::ShopHealthPotion);
			break;
		case 1:
			newItem = MakeShopItem(ShopItems::ShopAttackBoost);
			break;
		}
		if (newItem != nullptr) {
			character->GetItemInventory()->Insert(newItem);
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

void GameManager::ShopSellItem()
{
	std::vector<Item*> items = character->GetItemInventory()->GetItems();

	std::vector<std::string> options;
	for (int i = 0; i < items.size(); i++) {
		options.emplace_back(items[i]->GetName());
	}

	int sellIndex = SelectNumber(options);

	Item* item = character->GetItemInventory()->Get(sellIndex);
	if (item != nullptr) {
		int price = item->GetPrice() * 60 / 100;

		// temp message
		std::cout << item->GetName() << "을/를 " << price << "골드에 팔았습니다." << std::endl;

		character->GetItemInventory()->Remove(sellIndex);
		character->SetGold(character->GetGold() + price);
	}

	// temp message
	std::cout << "현재 소유 골드는 " << character->GetGold() << " 입니다." << std::endl;
}

void GameManager::ShopSellEquipment()
{
	// 가지고 있는 모든 장비 판매하기
	std::vector<Equipment*> eqiupments = character->GetEquipmentInventory()->GetItems();
	int gain = 0;
	int old_glod = character->GetGold();
	for (auto& equipment : eqiupments) {
		// temp message
		std::cout << equipment->GetName() << "를 " << equipment->GetPrice() << " 에 팔았습니다.." << std::endl;
		gain += equipment->GetPrice();
	}
	int new_gold = old_glod + gain;
	character->SetGold(new_gold);

	// temp message
	std::cout << "현재 골드: " << character->GetGold() << " (+" << gain << ")" << std::endl;
}

