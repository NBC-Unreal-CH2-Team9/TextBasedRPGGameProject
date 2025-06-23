#include "Monster.h"
#include "Dragon.h"
#include "Orc.h"
#include "Goblin.h"
#include "Slime.h"

void Monster::Attack(Actor& other)
{
	std::cout << name << "��(��) " << other.GetName() << "��(��) �����մϴ�! ";
	other.TakeDamage(attack);
}

void Monster::TakeDamage(int damage)
{
	health -= damage;
	if (health > 0)
	{
		std::cout << name << "ü��: " << health << std::endl;
	}
	else
	{
		std::cout << name << "óġ!" << std::endl;
	}
}

Monster* MonsterManager::CreateDragon(int characterLevel)
{
	int health = CalculateHealth(characterLevel) * 1.5;
	int attack = CalculateAttack(characterLevel) * 1.5;
	Monster* dragon = new Dragon("�巡��", health, attack);
	return dragon;
}

Monster* MonsterManager::CreateOrc(int characterLevel)
{
	int health = CalculateHealth(characterLevel);
	int attack = CalculateAttack(characterLevel);
	Monster* orc = new Orc("��ũ", health, attack);
	return orc;
}

Monster* MonsterManager::CreateSlime(int characterLevel)
{
	int health = CalculateHealth(characterLevel);
	int attack = CalculateAttack(characterLevel);
	Monster* slime = new Slime("������", health, attack);
	return slime;
}

Monster* MonsterManager::CreateGoblin(int characterLevel)
{
	int health = CalculateHealth(characterLevel);
	int attack = CalculateAttack(characterLevel);
	Monster* goblin = new Goblin("���", health, attack);
	return goblin;
}

Monster* MonsterManager::CreateTroll(int characterLevel)
{
	int health = CalculateHealth(characterLevel) * 1.5;
	int attack = CalculateAttack(characterLevel) * 1.5;
	Monster* dragon = new Dragon("�巡��", health, attack);
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
