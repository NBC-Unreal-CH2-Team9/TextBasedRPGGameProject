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
#include "../Console/ConsoleOutput.h"

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
	ConsoleOutput::ShowCreateCharacterIntro();
	ConsoleOutput::ShowCreateCharacterName();
	std::string name;
	std::cin >> name;

	std::vector<std::string> jobOptions = { "검사", "마법사", "탱커" };
	int jobChoice = ConsoleInput::SelectNumber(jobOptions);

	switch (jobChoice)
	{
	case 0:
		character = new Warrior(1, name, 200, 30, 0);
		break;
	case 1:
		character = new Mage(1, name, 100, 45, 0);
		break;
	case 2:
		character = new Tanker(1, name, 350, 15, 0);
		break;
	default:
		break;
	}

	return character;
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

void GameManager::Shop()
{
	if (ConsoleInput::SelectYesOrNo(ConsoleOutput::shopQuestion)) {

		ConsoleOutput::ShowEnterShop();

		// 상점에 방문했을 때, 사용하지 않는 모든 장비를 판매함
		ShopSellEquipment();

		while (true) {
			int select = ConsoleInput::SelectNumber(ConsoleOutput::shopOptions);
			switch (select) {
			case 0:
				ShopBuyItem();
				break;
			case 1:
				if (character->GetItemInventory()->Count() > 0) {
					ShopSellItem();
				}
				else {
					ConsoleOutput::ShowNoItemToSell();
				}
				break;
			case 2:
				ConsoleOutput::ShowExitShop();
				return;
			}
		}
	}
	else {
		ConsoleOutput::ShowSkipShop();
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

	ConsoleOutput::ShowCharacterGold(*character);
	std::vector<std::string> options = ConsoleOutput::MakeShopBuyList(shopItems);
	int buyIndex = ConsoleInput::SelectNumber(options);

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

			ConsoleOutput::ShowBuyItem(*newItem, *character);
		}
	}
	else {
		ConsoleOutput::ShowNotEnoughGold();
	}
	
}

void GameManager::ShopSellItem()
{
	std::vector<Item*> items = character->GetItemInventory()->GetItems();

	float ratio = 0.6f;
	std::vector<std::string> options = ConsoleOutput::MakeShopSellList(items, ratio);
	int sellIndex = ConsoleInput::SelectNumber(options);

	Item* item = character->GetItemInventory()->Get(sellIndex);
	if (item != nullptr) {
		int price = (int)(item->GetPrice() * ratio);

		ConsoleOutput::ShowSellItem(*item, *character, ratio);
		character->GetItemInventory()->Remove(sellIndex);
		character->SetGold(character->GetGold() + price);
	}
}

void GameManager::ShopSellEquipment()
{
	std::vector<Equipment*> eqiupments = character->GetEquipmentInventory()->GetItems();
	for (Equipment* equipment : eqiupments) {
		character->SetGold(character->GetGold() + equipment->GetPrice());
		ConsoleOutput::ShowSellEquipment(*equipment, *character, 1);
	}
}

