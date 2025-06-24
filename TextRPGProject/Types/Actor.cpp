#include "Actor.h"

bool Actor::isCriticalHit()
{
    if (rand() % 100 < criticalProbablily)
    {
        return true;
    }

    return false;    
}
