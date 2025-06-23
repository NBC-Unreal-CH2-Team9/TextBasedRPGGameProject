#include "Mage.h"  
#include <iostream>  

void Mage::OnLevelChangedHealth() {  
	std::cout << "Mage's health increased!" << std::endl;
	int newHealth = (maxHealth + level * 20);  
	health = newHealth;  
	maxHealth = newHealth;  
}  

void Mage::OnLevelChangedAttack() { 
	std::cout << "Mage's attack increased!" << std::endl;  
	attack += (level * 5);  
}