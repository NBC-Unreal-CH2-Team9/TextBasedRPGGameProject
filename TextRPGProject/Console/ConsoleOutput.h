#pragma once
#include <string>

class ConsoleOutput
{
public:
	static void ShowCharacterStatusvoid(int level, int experience, int health, int maxHealth, int attackpower);
	static void ShowCharacterGold(int gold);

	static void ShowMonsterStatus(int level, int health);

	static void MonsterAttack(std::string monster, std::string charactor);
	static void CharactorAttack(std::string Charactor, std::string monster);

	static void DieMonster();

};
