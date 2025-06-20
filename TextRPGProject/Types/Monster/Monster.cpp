#include "Monster.h"

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
