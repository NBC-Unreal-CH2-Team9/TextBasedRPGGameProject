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


	//std::cout << mon->GetCriticalAttack() << std::endl;
	std::cout << mon->GetAttack() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		//std::cout << mon->GetCriticalProbablily() << std::endl;
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
  testMonster();
}

