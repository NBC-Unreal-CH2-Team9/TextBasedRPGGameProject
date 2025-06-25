#include "Monster.h"
#include "Dragon.h"
#include "Orc.h"
#include "Goblin.h"
#include "Slime.h"
#include "Troll.h"
#include "BossMonster.h"

Monster* MonsterManager::CreateDragon(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 100, 150);
	int attack = CalculateAttack(characterLevel, 15, 20);
	int gold = CalculateGold(100, 150);
	int experience = 100;
	Monster dragon("드래곤", health, attack, gold, experience);
	return CreateBoss(dragon);
}

Monster* MonsterManager::CreateOrc(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 40, 60);
	int attack = CalculateAttack(characterLevel, 2, 7);
	int gold = CalculateGold(20, 30);
	int experience = 75;
	Monster* orc = new Orc("오크", health, attack, gold, experience);
	return orc;
}

Monster* MonsterManager::CreateSlime(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 10, 20);
	int attack = CalculateAttack(characterLevel, 1, 5);
	int gold = CalculateGold(5, 15);
	int experience = 25;
	Monster* slime = new Slime("슬라임", health, attack, gold, experience);
	return slime;
}

Monster* MonsterManager::CreateGoblin(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 20, 30);
	int attack = CalculateAttack(characterLevel, 5, 10);
	int gold = CalculateGold(10, 20);
	int experience = 50;
	Monster* goblin = new Goblin("고블린", health, attack, gold, experience);
	return goblin;
}

Monster* MonsterManager::CreateTroll(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 25, 40);
	int attack = CalculateAttack(characterLevel, 6, 12);
	int gold = CalculateGold(15, 25);
	int experience = 60;
	Monster* troll = new Troll("트롤", health, attack, gold, experience);
	return troll;
}

Monster* MonsterManager::CreateBoss(Monster& monster)
{
	std::string name = "보스 " + monster.GetName();
	int health = monster.GetHealth() * 1.5;
	int attack = monster.GetAttack() * 1.5;
	int gold = monster.GetGold() * 1.5;
	int experience = monster.GetExperience() * 1.5;
	Monster* bossMonster = new BossMonster(name, health, attack, gold, experience);

	return bossMonster;
}


int MonsterManager::CalculateHealth(int characterLevel, int minHealth, int maxHealth)
{
	int andHelth = maxHealth - minHealth + 1;
	return (rand() % andHelth + minHealth) * characterLevel;
}

int MonsterManager::CalculateAttack(int characterLevel, int minAttack, int maxAttack)
{
	int andAttack = maxAttack - minAttack + 1;
	return (rand() % andAttack + minAttack) * characterLevel;
}

int MonsterManager::CalculateGold(int minGold, int maxGold)
{
	int andGold = maxGold - minGold + 1;
	return rand() % andGold + minGold;
}
