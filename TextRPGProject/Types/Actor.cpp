#include "Actor.h"
#include "../Console/ConsoleOutput.h"

void Actor::Attack(Actor& other)
{
    ConsoleOutput::ShowAttackMessage(*this, other);
    int damage = ApplyCriticalAttack();
    other.TakeDamage(damage);
}

void Actor::TakeDamage(int damage)
{
    ConsoleOutput::ShowDamageMessage(*this, damage);
    health -= damage;
}


bool Actor::isCriticalHit()
{
	int num = rand() % 100;

    if (num < criticalProbablily)
    {
        ConsoleOutput::ShowCriticalHit();
        return true;
    }
    else
    {
        return false;
    }
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
