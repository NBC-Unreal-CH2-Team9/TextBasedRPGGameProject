#include "Actor.h"

int Actor::GetAttack()
{
    if (isCriticalHit())
    {
        return attack * criticalAttack;
    }
    
    return attack;
}

bool Actor::isCriticalHit()
{
    if (rand() % 100 < criticalProbablily)
    {
        return true;
    }

    return false;    
}
