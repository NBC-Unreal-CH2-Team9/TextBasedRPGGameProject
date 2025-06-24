#pragma once

#include "../Types/Character/Character.h"

#include "../Types/Monster/Monster.h"
#include "../Types/Actor.h"

struct BattleResult {
public:
	bool isWin;
	bool isBoss;
};

class GameManager {

public:
	GameManager();
	~GameManager();
	
	Character* CreateCharacter();
	BattleResult Battle();
	void Shop();

	Character* GetCharacter() {
		return character;
	}

protected:
	void ShopBuyItem();
	void ShopSellItem();
	void ShopSellEquipment();
	
	Character* character;
	Monster* monster;
	int monsterNum;

private:
	void GenerateMonster(int characterLevel);
	void CheckHealthPotionAndUse();

	// 상점에서 사용하는 정적 변수 모음
	static const std::string shopMessage;
	static const std::vector<std::string> shopPrompt;

	// 상점에서 사용하는 정적 함수 모음
	// 상점에서 판매하는 아이템 생성
	enum ShopItems {
		ShopHealthPotion = 0,
		ShopAttackBoost = 1,
	};
	static Item* MakeShopItem(ShopItems index);
};