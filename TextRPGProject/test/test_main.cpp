#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Types/Monster/Monster.h"

#include "../Types/Item/Item.h"

void testBattle() {
	GameManager gameManager;
	gameManager.CreateCharacter();
	gameManager.Battle();
}


void testMonster()
{
	srand(time(nullptr));
	int playerLevel = 1;
	Monster* mon = MonsterManager::CreateOrc(playerLevel);
	Monster* bossMon = MonsterManager::CreateBoss(*mon);

	std::cout << mon->GetName() << std::endl;
	std::cout << mon->GetHealth() << std::endl;
	std::cout << mon->GetAttack() << std::endl;
	std::cout << mon->GetGold() << std::endl;
	std::cout << mon->GetExperience() << std::endl;

	std::cout << "보스" << std::endl;
	std::cout << bossMon->GetName() << std::endl;
	std::cout << bossMon->GetHealth() << std::endl;
	std::cout << bossMon->GetAttack() << std::endl;
	std::cout << bossMon->GetGold() << std::endl;
	std::cout << bossMon->GetExperience() << std::endl;
	
	
}

void testShop() {
	GameManager gameManager;
	gameManager.CreateCharacter();

	// 장비를 얻었다고 가정하기

	Character* character = gameManager.GetCharacter();
	character->GetEquipmentInventory()->Insert(new Equipment("임시장비1", 100));
	character->GetEquipmentInventory()->Insert(new Equipment("임시장비2", 30));

	gameManager.Shop();

}

int main() {
  testMonster();
}

