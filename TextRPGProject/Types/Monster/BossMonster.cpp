#include "BossMonster.h"
/*
void BossMonster::Attack(Actor& other)
{
	std::cout << name << "이(가) " << other.GetName() << "을(를)";

	if (rand() % 10 < 2)
	{
		UseSkill(other, name);
	}
	else
	{
		std::cout << " 공격합니다! ";
		other.TakeDamage(attack);
	}

}*/

void BossMonster::UseSkill(Actor& other, std::string name)
{
	std::cout << name << "이(가) 스킬을 사용했다." << std::endl;

	if (name == "고블린" || name == "트롤")
	{
		AttackSkill(other);
	}
	else if (name == "슬라임" || name == "오크")
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
