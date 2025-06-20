#include "Monster.h"

void Monster::Attack(Actor& other)
{
	std::cout << name << "이(가) " << other.GetName() << "을(를) 공격합니다! ";
	other.TakeDamage(attack);
}

void Monster::TakeDamage(int damage)
{
	health -= damage;
	if (health > 0)
	{
		std::cout << name << "체력: " << health << std::endl;
	}
	else
	{
		std::cout << name << "처치!" << std::endl;
	}
}
