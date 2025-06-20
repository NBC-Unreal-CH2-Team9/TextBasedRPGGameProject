#include "Character.h"
#include <iostream>

void Character::Attack(Actor& other)
{	
	other.TakeDamage(attack);	
}

void Character::TakeDamage(int damage)
{
	health -= damage;
	if (health < 0) {
		// TODO : ���� �ý����� ���� ���� ó�� �Լ� ȣ��
	}
}

void Character::DisplayStatus()
{
	std::cout << "==Status==" << std::endl;
	std::cout << "level:" << level << std::endl;
	std::cout << "experience:" << experience << std::endl;
	std::cout << "health:" << health << std::endl;
	std::cout << "maxHealth:" << maxHealth << std::endl;
	std::cout << "attack:" << attack << std::endl;	
}

void Character::LevelUp()
{	
	if (level < 10) {
		level++;
		std::cout << "Level Up!" << std::endl;		
		UpdateHealth();
		UpdateAttack();
	}	
}

void Character::UpdateHealth()
{
	int newHealth = (maxHealth + level * 20);
	health = newHealth;
	maxHealth = newHealth;	
}

void Character::UpdateAttack()
{
	attack += (level * 5);		
}

void Character::UpdateExperience(int exp)
{
	int newExp = experience + exp; // ���� ����ġ + �߰� ����ġ
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; // ������ �� ����ġ�� �ʱ�ȭ
	}
}
