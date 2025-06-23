#pragma once

#include "../Types/Monster/Monster.h"
#include "../Types/Character/Character.h"
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

	void CreateCharacter();
	BattleResult Battle();
	void Shop();

private:
	void GenerateMonster(int characterLevel);
	void FightUntilDeath(Actor* attacker,Actor* defender);

	void ShopBuy();
	void ShopSell();

	Monster* monsters[4];
	int monsterNum;
	int totalMonsterHealth;
	int totalMonsterAttack;
	bool isMyTurn;
	bool isFighting;

	Character* GetCharacter() {
		return character;
	}

protected:
	Character* character;

private:
	static const std::string shopMessage;
	static const std::vector<std::string> shopPrompt;

};