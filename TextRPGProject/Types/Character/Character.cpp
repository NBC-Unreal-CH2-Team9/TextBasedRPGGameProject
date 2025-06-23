#include "Character.h"
#include "Inventory.h"
#include <iostream>

void Character::Attack(Actor& other)
{	
	other.TakeDamage(attack);	
}

void Character::TakeDamage(int damage)
{
	health -= damage;	
	// hp�� 10���Ϸ� �������� ��� �����ϰ� ������ ���
	if (health > 0 && health <= 10) {
		UseRandomItem();
	}
}

void Character::DisplayStatus()
{
	std::cout << "==Status==" << std::endl;
	std::cout << "name:" << name << std::endl;
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
}

void Character::UseRandomItem()
{
	// TODO: �����ϰ� ������ ���
	std::vector<Item*> items = inventory.GetItems();
}

void Character::GetRandomItem(Item* item)
{
	inventory.Insert(item);	
}