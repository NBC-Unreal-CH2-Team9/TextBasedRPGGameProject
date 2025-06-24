#include "Actor.h"
#include "../Console/ConsoleOutput.h"

void Actor::Attack(Actor& other)
{
    ConsoleOutput::ShowAttackMessage(*this, other);
    other.TakeDamage(GetAttack());
}

void Actor::TakeDamage(int damage)
{
    ConsoleOutput::ShowDamageMessage(*this, damage);
    health -= damage;
}

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
        ConsoleOutput::ShowCriticalHit();
        return true;
    }
    else
    {
        return false;
    }
}
