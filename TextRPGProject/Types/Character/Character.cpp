#include "Character.h"
#include "Inventory.h"
#include <iostream>

void Character::LevelUp()
{	
	if (level < 10) {
		level++;
		std::cout << "Level Up!" << std::endl;
		OnLevelChangedHealth();
		OnLevelChangedAttack();
	}	
}

void Character::OnLevelChangedHealth() {}

void Character::OnLevelChangedAttack() {}

void Character::AddExperience(int exp)
{
	int newExp = experience + exp; // 현재 경험치 + 추가 경험치
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; // 레벨업 후 경험치를 초기화
	}
	else {
		experience = newExp;
	}
}

void Character::GetRandomItem(Item* item)
{
	itemInventory.Insert(item);
}