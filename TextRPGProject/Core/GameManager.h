#pragma once

#include "../Types/Monster.h""
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

	/* 필요하면 return type 변경 */
	BattleResult Battle(/*필요하면 parameter 추가*/);

	/* 필요하면 return type 변경 */
	void Shop(/*필요하면 parameter 추가*/);

private:
	void FightUntilDeath(Actor* attacker,Actor* defender);

private:
	Monster* monsters[4];
	int monsterNum;
	int totalMonsterHealth;
	int totalMonsterAttack;
	bool isMyTurn;
	bool isFighting;
};