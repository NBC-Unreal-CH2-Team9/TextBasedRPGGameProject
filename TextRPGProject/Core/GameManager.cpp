﻿#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <random>

#include "GameManager.h"

#include "../Types/Monster/Dragon.h"
#include "../Types/Monster/Goblin.h"
#include "../Types/Monster/Orc.h"
#include "../Types/Monster/Slime.h"
#include "../Types/Monster/Troll.h"

#include "../Types/Item/Item.h"
#include "../Types/Item/AttackBoost.h"
#include "../Types/Item/HealthPotion.h"
#include "../Types/Item/ItemManager.h"
#include "../Types/Equipment/EquipmentManager.h"

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

#include "../Types/Character/Warrior.h"
#include "../Types/Character/Mage.h"
#include "../Types/Character/Tanker.h"

GameManager::GameManager()
{
	character = nullptr;
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

	ConsoleOutput::ShowSelectJob();
	std::vector<std::string> jobOptions = { "검사", "마법사", "탱커" };
	int jobChoice = ConsoleInput::SelectNumber(jobOptions);

	switch (jobChoice)
	{
	case 0:
		character = new Warrior(1, name, 300, 35, 0);
		break;
	case 1:
		character = new Mage(1, name, 200, 50, 0);
		break;
	case 2:
		character = new Tanker(1, name, 500, 25, 0);
		break;
	default:
		break;
	}

	return character;
}

Monster* GameManager::GenerateMonster(int characterLevel, BattleResult::BattleType battleType)
{
	//다른 확률 몬스터 생성
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> monsterRandNum(0, 99);
	int randNum = monsterRandNum(gen);

	Monster* monster = nullptr;

	if (battleType == BattleResult::FINAL_BOSS) {
		monster = MonsterManager::CreateDragon(characterLevel);
	}
	else {
		//40,30,20,10
		if (randNum < 40)
		{
			monster = MonsterManager::CreateGoblin(characterLevel);
		}
		else if (randNum < 70)
		{
			monster = MonsterManager::CreateOrc(characterLevel);
		}
		else if (randNum < 90)
		{
			monster = MonsterManager::CreateSlime(characterLevel);
		}
		else
		{
			monster = MonsterManager::CreateTroll(characterLevel);
		}

		if (battleType == BattleResult::MID_BOSS)
		{
			Monster* bossMonster;
			bossMonster = MonsterManager::CreateBoss(*monster);
			delete monster;
			monster = bossMonster;
		}
	}

	ConsoleOutput::ShowMonsterStatus(*monster);
	return monster;
}


BattleResult GameManager::Battle()
{
	ConsoleOutput::ShowBattleStart();

	BattleResult result;
	result.isWin = false;

	bool isMyTurn = true;
	bool isFighting = true;

	if (character->GetLevel() >= 15)
	{
		result.battleType = BattleResult::FINAL_BOSS;
	}
	else if (character->GetLevel() >= 10) {
		result.battleType = BattleResult::MID_BOSS;
	}
	else {
		result.battleType = BattleResult::NORMAL;
	}
	Monster* monster = GenerateMonster(character->GetLevel(), result.battleType);

	UseAttackBooster();

	//전투중
	while(isFighting)
	{
		if (isMyTurn)
		{
			ConsoleOutput::ShowCharacterTurn();
			UseHealthPotion();
	
			character->Attack(*monster);
			if (monster->GetHealth() <= 0)
			{
				isFighting = false;
			}
		}
		else
		{
			ConsoleOutput::ShowMonsterTurn();
			monster->Attack(*character);
			if (character->GetHealth() <= 0)
			{
				isFighting = false;
			}
		}
		isMyTurn = !isMyTurn;
		
		ConsoleOutput::ShowBattleProgress(*character, *monster);
		// 약간의 딜레이
		Sleep(1000);
	}

	if (character->GetHealth() > 0)
	{
		result.isWin = true;
		ConsoleOutput::ShowBattleWin();
		character->SetGold(character->GetGold() + monster->GetGold());
		bool isLevelUp = character->AddExperienceAndCheckLevelUp(monster->GetExperience());
		ConsoleOutput::ShowGetGold(*character, *monster);
		ConsoleOutput::ShowGetExp(*character, *monster);

		RandomGetItem();

		if (isLevelUp) {
			ConsoleOutput::ShowLevelUp(*character);
		}
		
	}
	else
	{
		ConsoleOutput::ShowBattleDefeat();
	}

	delete monster;

	return result;
}


void GameManager::UseHealthPotion()
{
	if (character->GetHealth() > character->GetMaxHealth() / 2) {
		return;
	}

	if (!character->GetItemInventory()->Count()) {
		return;
	}

	std::vector<Item*> Items = character->GetItemInventory()->GetItems();

	for (int i = 0; i < Items.size(); i++)
	{
		if (Items[i] && Items[i]->GetName() == "Health Potion")
		{
			Items[i]->Use(*character);
			HealthPotion* potion = dynamic_cast<HealthPotion*>(Items[i]);
			ConsoleOutput::ShowUseHealthPotion(*character, *potion);
			delete Items[i];
			character->GetItemInventory()->Remove(i);
			break;
		}
	}
}

void GameManager::UseAttackBooster()
{
	if (!character->GetItemInventory()->Count()) {
		return;
	}

	std::vector<Item*> Items = character->GetItemInventory()->GetItems();

	int attackBoostNum = 0;

	for (int i = 0; i < Items.size(); i++)
	{
		if (Items[i]->GetName() == "Attack Boost") 
		{
			Items[i]->Use(*character);
			AttackBoost* boost = dynamic_cast<AttackBoost*>(Items[i]);
			ConsoleOutput::ShowUseAttackBoost(*character, *boost);
			delete Items[i];
			character->GetItemInventory()->Remove(i-attackBoostNum);
			attackBoostNum++;
		}

	}
}


void GameManager::Shop()
{
	ConsoleOutput::ShowShopStart();
	if (ConsoleInput::SelectYesOrNo(ConsoleOutput::shopQuestion)) {

		ConsoleOutput::ShowEnterShop();

		// 상점에 방문했을 때, 사용하지 않는 모든 장비를 판매함
		ShopSellEquipment();

		while (true) {

			ConsoleOutput::ShowCharacterGoldAndItem(*character);

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
	int shop_attackincrease = 10;
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

void GameManager::DropEquip()
{
	Equipment* dropEquip = EquipmentManager::GenerateRandomEquipment();
	ConsoleOutput::ShowDropEquip(*dropEquip);
	character->Equip(dropEquip);
}

void GameManager::DropItem()
{
	Item* dropItem = ItemManager::GenerateRandomItem();
	ConsoleOutput::ShowDropItem(*dropItem);
	character->GetRandomItem(dropItem);
}

void GameManager::RandomGetItem()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);

	int itemRoll = dist(gen);
	int equipRoll = dist(gen);
	

	if (itemRoll <= 30)
	{
		DropItem();
	}

	if (equipRoll <= 10)
	{
		DropEquip();
	}
}

void GameManager::ShopBuyItem()
{
	std::vector<Item*> shopItems;
	shopItems.push_back(MakeShopItem(ShopItems::ShopHealthPotion));
	shopItems.push_back(MakeShopItem(ShopItems::ShopAttackBoost));

	int gold = character->GetGold();

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
	
	for (Item* item : shopItems) {
		delete item;
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
		character->GetItemInventory()->Remove(sellIndex);
		character->SetGold(character->GetGold() + price);
		ConsoleOutput::ShowSellItem(*item, *character, ratio);
		delete item;
	}
}

void GameManager::ShopSellEquipment()
{
	std::vector<Equipment*> eqiupments = character->GetEquipmentInventory()->GetItems();
	for (Equipment* equipment : eqiupments) {
		character->SetGold(character->GetGold() + equipment->GetPrice());
		ConsoleOutput::ShowSellEquipment(*equipment, *character, 1);
	}
	character->GetEquipmentInventory()->Clear(); // 인벤토리 비우기
}
