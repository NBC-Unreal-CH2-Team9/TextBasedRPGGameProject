#include "Monster.h"
#include "Dragon.h"
#include "Orc.h"
#include "Goblin.h"
#include "Slime.h"

void Monster::Attack(Actor& other)
{
	other.TakeDamage(attack);
}

void Monster::TakeDamage(int damage)
{
	health -= damage;
	if (health > 0)
	{
	}
	else
	{
	}
}

Monster* MonsterManager::CreateDragon(int characterLevel)
{
	int health = CalculateHealth(characterLevel) * 1.5;
	int attack = CalculateAttack(characterLevel) * 1.5;
	Monster* dragon = new Dragon("드래곤", health, attack);
	return dragon;
}

Monster* MonsterManager::CreateOrc(int characterLevel)
{
	int health = CalculateHealth(characterLevel);
	int attack = CalculateAttack(characterLevel);
	Monster* orc = new Orc("오크", health, attack);
	return orc;
}

Monster* MonsterManager::CreateSlime(int characterLevel)
{
	int health = CalculateHealth(characterLevel);
	int attack = CalculateAttack(characterLevel);
	Monster* slime = new Slime("슬라임", health, attack);
	return slime;
}

Monster* MonsterManager::CreateGoblin(int characterLevel)
{
	int health = CalculateHealth(characterLevel);
	int attack = CalculateAttack(characterLevel);
	Monster* goblin = new Goblin("고블린", health, attack);
	return goblin;
}

Monster* MonsterManager::CreateTroll(int characterLevel)
{
	int health = CalculateHealth(characterLevel) * 1.5;
	int attack = CalculateAttack(characterLevel) * 1.5;
	Monster* troll = new Troll("트롤", health, attack);
	return dragon;
}


int MonsterManager::CalculateHealth(int characterLevel)
{
	return (rand() % 11 + 20) * characterLevel;
}

int MonsterManager::CalculateAttack(int characterLevel)
{
	return (rand() % 6 + 5) * characterLevel;
}