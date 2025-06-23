#include "Warrior.h"
#include <iostream>

void Warrior::OnLevelChangedHealth() {
	std::cout << "Warrior's health increased!" << std::endl;

	int newHealth = (maxHealth + level * 20);
	health = newHealth;
	maxHealth = newHealth;	
}

void Warrior::OnLevelChangedAttack() {
	std::cout << "Warrior's attack increased!" << std::endl;
	attack += (level * 5);
}