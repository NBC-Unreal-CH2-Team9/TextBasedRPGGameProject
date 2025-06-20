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
	character = new Character("�ӽ�", 100, 10);
	character->SetGold(100);
}

BattleResult GameManager::Battle()
{
	// �ʼ� ��� [3]
	// ���� �ý���
	// ĳ���� ���� ����, �׸��� ���� �湮(�Ǵ� ��ŵ) ����

	// �ʼ� ��� [4]
	// ���� ����

	// ���� ����
	// ���� ���� ����ڰ� ����
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
	"���� ���", "���� �ȱ�", "���� ������"
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
	std::cout << "���� ���: " << character->GetGold() << std::endl;

	std::vector<std::string> options;
	for (int i = 0; i < shopItems.size(); i++) {
		options.emplace_back(shopItems[i]->GetName() + ", (" + std::to_string(prices[i]) + "���)");
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
			std::cout << newItem->GetName() << "��/�� �����߽��ϴ�. "
				<< "(���� ���: " << gold << ")" << std::endl;
		}
	}
	else {
		// temp message
		std::cout << "��尡 ���ڶ��ϴ�" << std::endl;
	}
	
}

void GameManager::ShopSell()
{
	std::vector<Item*> items = character->GetInventory()->GetItems();
}
