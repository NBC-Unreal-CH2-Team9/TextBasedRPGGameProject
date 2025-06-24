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
	int newExp = experience + exp; // ���� ����ġ + �߰� ����ġ
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; // ������ �� ����ġ�� �ʱ�ȭ
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