#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

#include "../Types/Item/Item.h"

void testBattle() {
	GameManager gameManager;
	gameManager.CreateCharacter();
	gameManager.Battle();
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
	testShop();
}

