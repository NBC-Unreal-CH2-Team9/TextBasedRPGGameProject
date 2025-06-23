#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

void testBattle() {
	GameManager gameManager;
	gameManager.CreateCharacter();
	
	while (1)
	{
		gameManager.Battle();
	}
	
}

int main() {
	testBattle();
	//TestUseHealthPotion();
}

