#include <vector>
#include <string>
#include <iostream>
#include "GameManager.h"
#include <iostream>
//#include "../Types/Goblin.h"
//#include "../Types/Orc.h"
//#include "../Types/Troll.h"
//#include "../Types/Slime.h"
#include <random>
#include "../Types/Item/Item.h"
#include "../Types/Item/AttackBoost.h"
#include "../Types/Item/HealthPotion.h"
#include "../Console/ConsoleInput.h"


GameManager::GameManager()
{
	//monsters[4] = { new Goblin("Goblin",200,100),new Orc("Orc",300,110),new Troll("Troll",400,120),new Slime("Slime",500,130)};

	character == nullptr;
}

GameManager::~GameManager()
{
	delete[] monsters;

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
	std::random_device rd;                
	std::mt19937 gen(rd());               
	std::uniform_int_distribution<> monsterSizeRange(0, 3);
	std::uniform_int_distribution<> monsterHealthRange(20, 30);
	std::uniform_int_distribution<> monsterAttackRange(5, 10);

	monsterNum = monsterSizeRange(gen);
	totalMonsterHealth = characterLevel * monsterHealthRange(gen);
	totalMonsterAttack = characterLevel * monsterAttackRange(gen);

	std::cout << " " << monsters[monsterNum]->GetName() << " 등장!";
	std::cout<<"체력:" << totalMonsterHealth	<< ", 공격력 : " << totalMonsterAttack <<"\n";

}

BattleResult GameManager::Battle()
{
	// 필수 기능 [3]
	// 전투 시스템
	// 캐릭터 생성 직후, 그리고 상점 방문(또는 스킵) 이후

	// 필수 기능 [4]
	// 몬스터 설명

	GenerateMonster(character->GetLevel());

	BattleResult result;
	result.isWin = false;
	result.isBoss = false;

	isMyTurn = true;
	isFighting = true;

	while(isFighting)
	{
		if (isMyTurn)
		{
			FightUntilDeath(character, monsters[monsterNum]);
		}
		else
		{
			FightUntilDeath(monsters[monsterNum], character);
		}
	}

	if (character->GetHealth() > 0)
	{
		result.isWin = true;
	}

	delete[] monsters;

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

void GameManager::FightUntilDeath(Actor* attacker,Actor* defender)
{
	std::cout << attacker->GetName() << "가 " << defender->GetName() << "를 공격합니다! ";

	Character* player = dynamic_cast<Character*>(defender);

	int defenderHealth;

	if (player)
	{
		defender->TakeDamage(totalMonsterAttack);
		defenderHealth = defender->GetHealth();
	}
	else
	{
		totalMonsterHealth = totalMonsterHealth - attacker->GetAttack();
		defenderHealth = totalMonsterHealth;
	}


	if (defenderHealth <= 0)
	{
		std::cout << defender->GetName() << " 처치!\n";
		isFighting = false;
	}
	else
	{
		std::cout << defender->GetName() << " 체력:" << defender->GetHealth() << "\n";
	}

	isMyTurn = !isMyTurn;
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

