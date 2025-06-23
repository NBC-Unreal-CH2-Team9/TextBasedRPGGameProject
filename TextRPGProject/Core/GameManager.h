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

	/* 필요하면 return type 추가 */
	void CreateCharacter(/*필요하면 parameter 추가*/);

	void GenerateMonster(int characterLevel);

	BattleResult Battle();

private:
	Monster* monsters[4];
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