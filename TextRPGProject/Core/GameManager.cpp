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
	"물건 사기", "물건 팔기", "상점 나가기"
};

void GameManager::Shop()
{
	// List of Items
	// Hardcoding..
	std::vector<Item*> shopItems;
	shopItems.push_back(new Potion("포션"));
	shopItems.push_back(new Potion("파워업"));
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
