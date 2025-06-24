#include "Dragon.h"

void Dragon::Attack(Actor& other)
{

	if (rand() % 10 < 2)
	{

		other.TakeDamage(attack * 2);
	}
	else
	{

		other.TakeDamage(attack);
	}
}
