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
	int newExp = experience + exp;
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; 
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

void Character::EquipSword(Sword* newSword)
{
	if (equipSword == nullptr || newSword->GetStat() > equipSword->GetStat()) {
		if (equipSword != nullptr) {
			int newAttack = attack - equipSword->GetStat();
			SetAttack(newAttack);
			equipmentInventory.Insert(new Sword(*equipSword));
			delete equipSword;
		}

		equipSword = newSword;
		int newAttack = attack + equipSword->GetStat();
		SetAttack(newAttack);
	}
	else {
		equipmentInventory.Insert(new Sword(*newSword));
		delete newSword;
	}

}

void Character::EquipArmor(Armor* newArmor)
{
	if (equipArmor == nullptr || newArmor->GetStat() > equipArmor->GetStat())
	{
		if (equipArmor != nullptr) {
			maxHealth = maxHealth - equipArmor->GetStat();
			equipmentInventory.Insert(new Armor(*equipArmor));
			delete equipArmor;
		}

		equipArmor = newArmor;

		maxHealth = maxHealth + equipArmor->GetStat();
		health = health + equipArmor->GetStat();
		if (health > maxHealth) {
			health = maxHealth;
		}
			
	}
	else
	{
		equipmentInventory.Insert(new Armor(*newArmor));
		delete newArmor;
	}
}

void Character::Equip(Equipment* newEquip) {
	Equipment::EquipmentType type = newEquip->GetType();

	if (type == Equipment::EquipmentType::SWORD) {
		EquipSword(dynamic_cast<Sword*>(newEquip));
	}
	else if (type == Equipment::EquipmentType::ARMOR) {
		EquipArmor(dynamic_cast<Armor*>(newEquip));
	}
}
