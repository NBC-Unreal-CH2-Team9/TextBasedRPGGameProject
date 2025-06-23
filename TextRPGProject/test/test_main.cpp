#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

#include "../Types/Character/Character.h"

void testBattle() {
	GameManager gameManager;
	gameManager.CreateCharacter();
	gameManager.Battle();
}

void testCharacter() {
	GameManager gameManager;
	Character* c = gameManager.CreateCharacter();
	gameManager.Battle();

	c->DisplayStatus();
	for(int i = 0; i < 10; ++i) {
		c->AddExperience(100);
	}
}

int main() {
	testCharacter();
}

