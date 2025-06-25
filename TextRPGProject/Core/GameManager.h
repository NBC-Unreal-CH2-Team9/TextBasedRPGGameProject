#pragma once

#include "../Types/Character/Character.h"

#include "../Types/Monster/Monster.h"
#include "../Types/Actor.h"

struct BattleResult {
public:
	enum BattleType {
		NORMAL = 100,
		MID_BOSS = 200,
		FINAL_BOSS = 300,
	};
	bool isWin;
	BattleType battleType;
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


	void DropEquip();
	void DropItem();
	void RandomGetItem();

protected:
	void ShopBuyItem();
	void ShopSellItem();
	void ShopSellEquipment();
	
	Character* character;

private:
	Monster* GenerateMonster(int characterLevel, BattleResult::BattleType battleType);
	void UseHealthPotion();
	void UseAttackBooster();

	// 상점에서 사용하는 정적 함수 모음
	// 상점에서 판매하는 아이템 생성
	enum ShopItems {
		ShopHealthPotion = 0,
		ShopAttackBoost = 1,
	};
	static Item* MakeShopItem(ShopItems index);
};