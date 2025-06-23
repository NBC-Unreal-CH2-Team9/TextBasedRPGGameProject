#include "Monster.h"
#include "Dragon.h"
#include "Orc.h"
#include "Goblin.h"
#include "Slime.h"
#include "Troll.h"

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

int Monster::GetGold()
{
	return gold;
}

int Monster::GetExperience()
{
	return experience;
}

Monster* MonsterManager::CreateDragon(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 100, 150) * 1.5;
	int attack = CalculateAttack(characterLevel, 15, 20) * 1.5;
	int gold = CalculateGold(100);
	int experience = 100;
	Monster* dragon = new Dragon("�巡��", health, attack, gold, experience);
	return dragon;
}

Monster* MonsterManager::CreateOrc(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 40, 60);
	int attack = CalculateAttack(characterLevel, 2, 7);
	int gold = CalculateGold(20);
	int experience = 75;
	Monster* orc = new Orc("��ũ", health, attack, gold, experience);
	return orc;
}

Monster* MonsterManager::CreateSlime(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 10, 20);
	int attack = CalculateAttack(characterLevel, 1, 5);
	int gold = CalculateGold(5);
	int experience = 25;
	Monster* slime = new Slime("������", health, attack, gold, experience);
	return slime;
}

Monster* MonsterManager::CreateGoblin(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 20, 30);
	int attack = CalculateAttack(characterLevel, 5, 10);
	int gold = CalculateGold(10);
	int experience = 50;
	Monster* goblin = new Goblin("���", health, attack, gold, experience);
	return goblin;
}

Monster* MonsterManager::CreateTroll(int characterLevel)
{
	int health = CalculateHealth(characterLevel, 25, 40);
	int attack = CalculateAttack(characterLevel, 6, 12);
	int gold = CalculateGold(15);
	int experience = 60;
	Monster* troll = new Troll("Ʈ��", health, attack, gold, experience);
	return troll;
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

int MonsterManager::CalculateGold(int value)
{
	return rand() % 11 + value;
}

int MonsterManager::RandGold(int minGold)
{
	return rand() % 11 + minGold;
}
