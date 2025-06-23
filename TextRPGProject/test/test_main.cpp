#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Types/Monster/Monster.h"

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

	
	std::cout << mon->GetCriticalAttack() << std::endl;
	std::cout << mon->GetAttack() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << mon->GetCriticalProbablily() << std::endl;
	}
}

int main() {
	//testBattle();
	testMonster();
}

