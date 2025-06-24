#include "BossMonster.h"

void BossMonster::Attack(Actor& other)
{
	
	if (rand() % 10 < 2)
	{
		UseSkill(other, name);
	}
	else
	{
		int damage = ApplyCriticalAttack();
		other.TakeDamage(damage);
	}

}

void BossMonster::UseSkill(Actor& other, std::string name)
{

	if (name == "���� ���" || name == "���� Ʈ��")
	{
		AttackSkill(other);
	}
	else if (name == "���� ������" || name == "���� ��ũ")
	{
		HealSkill();
	}
}

void BossMonster::HealSkill()
{
	int heal = maxHealth / 10;
	if (health + heal < maxHealth)
	{
		health += heal;
	}
	else
	{
		health = maxHealth;
	}
	
}

void BossMonster::AttackSkill(Actor& other)
{
	int damage = ApplyCriticalAttack() * 2;
	other.TakeDamage(damage);
}
