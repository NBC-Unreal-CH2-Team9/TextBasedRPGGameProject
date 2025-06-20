#pragma once

#include "../Types/Character/Character.h"

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

	/* í•„ìš”í•˜ë©´ return type ì¶”ê°€ */
	void CreateCharacter(/*í•„ìš”í•˜ë©´ parameter ì¶”ê°€*/);

<<<<<<< HEAD
	void GenerateMonster(int characterLevel);

	/* ÇÊ¿äÇÏ¸é return type º¯°æ */
	BattleResult Battle(/*ÇÊ¿äÇÏ¸é parameter Ãß°¡*/);

	/* ÇÊ¿äÇÏ¸é return type º¯°æ */
	void Shop(/*ÇÊ¿äÇÏ¸é parameter Ãß°¡*/);

private:
	void FightUntilDeath(Actor* attacker,Actor* defender);

private:
	Monster* monsters[4];
	int monsterNum;
	int totalMonsterHealth;
	int totalMonsterAttack;
	bool isMyTurn;
	bool isFighting;
=======
	/* í•„ìš”í•˜ë©´ return type ë³€ê²½ */
	BattleResult Battle(/*í•„ìš”í•˜ë©´ parameter ì¶”ê°€*/);

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
>>>>>>> f65649bf6c857c74f3b6030eb438625e0b70b32d
};