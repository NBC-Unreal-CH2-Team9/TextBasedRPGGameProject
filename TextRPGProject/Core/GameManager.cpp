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

#include "../Types/Character/Warrior.h"
#include "../Types/Character/Mage.h"
#include "../Types/Character/Tanker.h"

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

Character* GameManager::CreateCharacter()
{
	std::cout << "캐릭터 이름을 입력하세요: ";
	std::string name;
	std::cin >> name;

	std::cout << "캐릭터 직업을 선택하세요(1번, 2번, 3번) " << std::endl;
	std::cout << "1. 검사" << std::endl;
	std::cout << "2. 마법사" << std::endl;
	std::cout << "3. 탱커" << std::endl;
	int jobChoice;
	std::cin >> jobChoice;

	switch (jobChoice)
	{
	case 1:
		character = new Warrior(1, name, 200, 30, 0);
		break;
	case 2:
		character = new Mage(1, name, 100, 45, 0);
		break;
	case 3:
		character = new Tanker(1, name, 350, 15, 0);
		break;
	default:
		break;
	}		

	return character;
}

void GameManager::GenerateMonster(int characterLevel)
{
	//다른 확률 몬스터 생성

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> monsterRandNum(0, 99);

	int randNum = monsterRandNum(gen);

	//30,25,20,15,10
	if (randNum < 30)
	{
		monster = MonsterManager::CreateGoblin(characterLevel);
	}
	else if (randNum < 55)
	{
		monster = MonsterManager::CreateOrc(characterLevel);
	}
	else if (randNum < 75)
	{
		monster = MonsterManager::CreateSlime(characterLevel);
	}
	else if(randNum<90)
	{
		monster = MonsterManager::CreateTroll(characterLevel);
	}
	else if(randNum<100)
	{
		monster = MonsterManager::CreateDragon(characterLevel);
	}


	if (characterLevel >= 10)
	{
		std::cout << "보스 몬스터 " << monster->GetName() << " 등장!";
	}
	else
	{
		std::cout << "몬스터 " << monster->GetName() << " 등장!";
	}

	std::cout << "체력:" << monster->GetHealth() << ",공격력:" << monster->GetAttack() << std::endl;
}

BattleResult GameManager::Battle()
{
	BattleResult result;
	result.isWin = false;
	result.isBoss = false;

	bool isMyTurn = true;
	bool isFighting = true;

	GenerateMonster(character->GetLevel());

	if (character->GetLevel() >= 10)
	{
		result.isBoss = true;
	}

	//전투중
	while(isFighting)
	{
		if (isMyTurn)
		{
			character->Attack(*monster);

			if (monster->GetHealth() <= 0)
			{
				isFighting = false;
			}
		}
		else
		{
			CheckHealthPotionAndUse();

			monster->Attack(*character);

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
		std::cout << "전투에서 승리했습니다!";
		//character->SetGold(character->GetGold() + monster->GetGold());
		//character->AddExperience(monster->GetExperience());
		//std::cout << monster->GetExperience() << " EXP와 " << monster->GetGold() << "를 획득했습니다.\n";	
	}

	delete monster;

	return result;
}

const std::string GameManager::shopMessage = "";
const std::vector<std::string> GameManager::shopPrompt = {
	"물건 사기", "물건 팔기", "상점 나가기"
};

void GameManager::CheckHealthPotionAndUse()
{
	//회복 포션 유무 확인
	if (character->GetItemInventory()->Count())
	{
		std::vector<Item*> Items = character->GetItemInventory()->GetItems();

		int healthPotionIndex = -1;

		for (int i = 0; i < Items.size(); i++)
		{
			if (Items[i] && Items[i]->GetName() == "Health Potion")
			{
				std::string option = "포션 사용 여부";
				if (SelectYesOrNo(option))
				{
					std::cout << "포션을 사용하였습니다!\n";
					Items[i]->Use(*character);
					character->GetItemInventory()->Remove(i);

					//test
					//std::cout << character->GetHealth();
				}

				break;
			}
		}
	}
}

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

