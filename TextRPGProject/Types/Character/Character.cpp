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
		// TODO : 전투 시스템의 게임 오버 처리 함수 호출
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
	int newExp = experience + exp; // 현재 경험치 + 추가 경험치
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; // 레벨업 후 경험치를 초기화
	}
}
