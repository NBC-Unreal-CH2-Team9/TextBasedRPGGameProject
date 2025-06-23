#pragma once
#include <string>

class ConsoleOutput
{
public:
	static void ShowCharacterStatus(const int level, int health, int attackpower);
	static void ShowCharacterGold(int gold);

	static void ShowMonsterStatus(const int level, int health);

	static void MonsterAttack(const std::string monster, std::string charactor);
	static void CharactorAttack(const std::string Charactor, std::string monster);

	static void DieMonster();

};
