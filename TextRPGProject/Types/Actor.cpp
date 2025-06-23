#include "Actor.h"

bool Actor::GetCriticalProbablily()
{
    if (rand() % 100 < criticalProbablily)
    {
        return true;
    }

    return false;    
}
