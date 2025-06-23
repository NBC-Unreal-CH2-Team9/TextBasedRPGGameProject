#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

void testBattle() {
	GameManager gameManager;
	gameManager.CreateCharacter();
	gameManager.Battle();
}

void testShop() {
	GameManager gameManager;
	gameManager.CreateCharacter();
	gameManager.Shop();
}

int main() {
	//testBattle();
	testShop();
}

