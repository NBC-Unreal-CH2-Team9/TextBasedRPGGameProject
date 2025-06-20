#include <vector>
#include <string>

#include "GameManager.h"
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
	Potion(std::string name) : Item(name) {}
	virtual void Use(Character& user) override {}
};
class PowerUp : public Item {
public:
	PowerUp(std::string name) : Item(name) {}
	virtual void Use(Character& user) override {}
};


const std::string GameManager::shopMessage = "";
const std::vector<std::string> GameManager::shopPrompt = {
	"���� ���", "���� �ȱ�", "���� ������"
};

void GameManager::Shop()
{
	// List of Items
	// Hardcoding..
	std::vector<Item*> shopItems;
	shopItems.push_back(new Potion("����"));
	shopItems.push_back(new Potion("�Ŀ���"));
	std::vector<int> prices;
	prices.push_back(10);
	prices.push_back(100);

	// options for print
	std::vector<std::string> buyOptions;
	std::vector<std::string> sellOptions;

	int select = SelectNumber(shopPrompt);
	switch (select) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
}
