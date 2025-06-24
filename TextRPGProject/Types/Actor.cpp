#include "Actor.h"


bool Actor::isCriticalHit()
{
	int num = rand() % 100;

    if (num < criticalProbablily)
    {
        return true;
    }

    return false;    
}

int Actor::ApplyCriticalAttack()
{
	if (isCriticalHit())
	{
		return attack * criticalPower;
	}
	else
	{
		return attack;
	}
}
