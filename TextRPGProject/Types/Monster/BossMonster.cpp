#include "BossMonster.h"
#include "../../Console/ConsoleOutput.h"

void BossMonster::Attack(Actor& other)
{
	if (name == "보스 드래곤" && GetHealth() < GetMaxHealth() / 3 && passiveSkill)
	{
		PassiveSkill();
	}

	
	if (rand() % 10 < 2)
	{
		UseSkill(other, name);
	}
	else
	{
		ConsoleOutput::ShowAttackMessage(*this, other);
		int damage = ApplyCriticalAttack();
		other.TakeDamage(damage);
	}

}

void BossMonster::UseSkill(Actor& other, std::string name)
{
	if (name == "보스 드래곤")
	{
		if (GetHealth() > GetMaxHealth() / 2)
		{
			AttackSkill(other);
		}
		else
		{
			HealSkill();
		}
		
	}
	else if (name == "보스 고블린" || name == "보스 트롤")
	{
		AttackSkill(other);
	}
	else if (name == "보스 슬라임" || name == "보스 오크")
	{
		HealSkill();
	}
}

void BossMonster::HealSkill()
{
	int heal = maxHealth / 10;
	int oldHealth = health;
	if (health + heal < maxHealth)
	{
		health += heal;
	}
	else
	{
		health = maxHealth;
	}
	ConsoleOutput::ShowMonsterHealSkill(*this, (health - oldHealth));
}

void BossMonster::AttackSkill(Actor& other)
{
	int damage = ApplyCriticalAttack() * 2;
	ConsoleOutput::ShowMonsterAttackSkill(*this);
	other.TakeDamage(damage);
	
}

void BossMonster::PassiveSkill()
{
	attack += 20;
	passiveSkill = false;
	ConsoleOutput::ShowMonsterPassiveSkill(*this);
}
