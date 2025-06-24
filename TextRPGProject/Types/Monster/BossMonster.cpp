#include "BossMonster.h"
/*
void BossMonster::Attack(Actor& other)
{
	std::cout << name << "��(��) " << other.GetName() << "��(��)";

	if (rand() % 10 < 2)
	{
		UseSkill(other, name);
	}
	else
	{
		std::cout << " �����մϴ�! ";
		other.TakeDamage(attack);
	}

}*/

void BossMonster::UseSkill(Actor& other, std::string name)
{
	std::cout << name << "��(��) ��ų�� ����ߴ�." << std::endl;

	if (name == "���" || name == "Ʈ��")
	{
		AttackSkill(other);
	}
	else if (name == "������" || name == "��ũ")
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
	other.TakeDamage(attack * 2);
}
