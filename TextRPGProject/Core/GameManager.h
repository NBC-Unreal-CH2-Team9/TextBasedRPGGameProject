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

	/* �ʿ��ϸ� return type �߰� */
	void CreateCharacter(/*�ʿ��ϸ� parameter �߰�*/);

	void GenerateMonster(int characterLevel);

	/* �ʿ��ϸ� return type ���� */
	BattleResult Battle(/*�ʿ��ϸ� parameter �߰�*/);

	/* �ʿ��ϸ� return type ���� */
	void Shop(/*�ʿ��ϸ� parameter �߰�*/);

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