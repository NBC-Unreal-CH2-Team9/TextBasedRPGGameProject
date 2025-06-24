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

	std::string s = "Continue Battle ? ";
	while(SelectYesOrNo(s))
	{
		gameManager.Battle();
	}
	
}

void testMonster()
{
	srand(time(nullptr));
	int playerLevel = 1;
	Monster* mon = MonsterManager::CreateGoblin(playerLevel);
	Monster* mon2 = MonsterManager::CreateSlime(playerLevel);
	Monster* bossMon = MonsterManager::CreateBoss(*mon);
	std::cout << "name: " << mon->GetName() << " health: " << mon->GetHealth() << 
		" attack: " << mon->GetAttack() << " gold: " << mon->GetGold() << 
		" experience: " << mon->GetExperience() << std::endl;
	std::cout << "name: " << bossMon->GetName() << " health: " << bossMon->GetHealth() << 
		" attack: " << bossMon->GetAttack() << " gold: " << bossMon->GetGold() << 
		" experience: " << bossMon->GetExperience() << std::endl;


	std::cout << "\n\nhealth: " << mon->GetHealth() << std::endl;
	std::cout << "health: " << bossMon->GetHealth() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		
		mon->Attack(*bossMon);
		std::cout << bossMon->GetName() << "health: " << bossMon->GetHealth() << std::endl;
		bossMon->Attack(*mon);
		std::cout << mon->GetName() << "health: " << mon->GetHealth() << std::endl;
	}
	
	
	
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
	//testBattle();
	testMonster();
}

