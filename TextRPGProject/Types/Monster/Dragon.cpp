#include "Dragon.h"

void Dragon::Attack(Actor& other)
{

	std::cout << name << "이(가) " << other.GetName() << "을(를)";

	if (rand() % 10 < 2)
	{
		std::cout << " 브레스공격합니다. ";
		other.TakeDamage(attack * 2);
	}
	else
	{
		std::cout << " 공격합니다! ";
		other.TakeDamage(attack);
	}
}
