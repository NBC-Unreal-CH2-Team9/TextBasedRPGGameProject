#pragma once

#include "../Types/Character/Character.h"

#include "../Types/Monster/Monster.h"
#include "../Types/Actor.h"
#include "../Types/Character/Character.h"

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

	void GenerateMonster(int characterLevel);

	BattleResult Battle();

private:
	Monster* monsters[5];
	int monsterNum;

	void Shop();
	void ShopBuy();
	void ShopSell();

	Character* GetCharacter() {
		return character;
	}

protected:
	Character* character;

private:
	static const std::string shopMessage;
	static const std::vector<std::string> shopPrompt;

};