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
	int newExp = experience + exp; // ���� ����ġ + �߰� ����ġ
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; // ������ �� ����ġ�� �ʱ�ȭ
	}
	else {
		experience = newExp;
	}
}

void Character::GetRandomItem(Item* item)
{
	itemInventory.Insert(item);
}