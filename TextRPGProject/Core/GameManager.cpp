#include <vector>
#include <string>
#include <iostream>

#include "GameManager.h"
#include "../Types/Item/Item.h"
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

BattleResult GameManager::Battle()
{
	// 필수 기능 [3]
	// 전투 시스템
	// 캐릭터 생성 직후, 그리고 상점 방문(또는 스킵) 이후

	// 필수 기능 [4]
	// 몬스터 설명

	// 전투 로직
	// 전투 로직 담당자가 구현
	// while () {
	// ...
	// }

	BattleResult result;
	result.isWin = false;
	result.isBoss = false;
	return result;
}

// Temporal Items for Shop TEST
#include "../Types/Item/Item.h"
class Potion : public Item {
public:
	Potion() : Item("HP Potion") {}
	virtual void Use(Character& user) override {}
};
class PowerUp : public Item {
public:
	PowerUp() : Item("Attack PowerUp") {}
	virtual void Use(Character& user) override {}
};


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
		case 1: // Buy
			ShopBuy();
			break;
		case 2: // Sell
			ShopSell();
			break;
		case 3: // Exit 
			return;
		}
	}
}

void GameManager::ShopBuy()
{
	// Hardcoding..
	std::vector<Item*> shopItems;
	shopItems.push_back(new Potion());
	shopItems.push_back(new PowerUp());
	std::vector<int> prices;
	prices.push_back(10);
	prices.push_back(100);

	int gold = character->GetGold();

	// temp message
	std::cout << "소유 골드: " << character->GetGold() << std::endl;

	std::vector<std::string> options;
	for (int i = 0; i < shopItems.size(); i++) {
		options.emplace_back(shopItems[i]->GetName() + ", (" + std::to_string(prices[i]) + "골드)");
	}
	
	int buyIndex = SelectNumber(options);

	if (gold >= prices[buyIndex - 1]) {
		gold -= prices[buyIndex - 1];
		// TODO: refactoring...
		Item* newItem = nullptr;
		switch (buyIndex) {
		case 1:
			newItem = new Potion();
			break;
		case 2:
			newItem = new PowerUp();
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
}
