#include <iostream>
#include "Character.h"
#include "Inventory.h"

void Character::LevelUp()
{	
	if (level < 10) {
		level++;
		OnLevelChangedHealth();
		OnLevelChangedAttack();
	}	
}

void Character::OnLevelChangedHealth() {}

void Character::OnLevelChangedAttack() {}

bool Character::AddExperienceAndCheckLevelUp(int exp)
{
	int newExp = experience + exp; // 현재 경험치 + 추가 경험치
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; // 레벨업 후 경험치를 초기화
		return true;
	}
	else {
		experience = newExp;
		return false;
	}
}

void Character::GetRandomItem(Item* item)
{
	itemInventory.Insert(item);
}