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

	// ��� ����ٰ� �����ϱ�

	Character* character = gameManager.GetCharacter();
	character->GetEquipmentInventory()->Insert(new Equipment("�ӽ����1", 100));
	character->GetEquipmentInventory()->Insert(new Equipment("�ӽ����2", 30));

	gameManager.Shop();
}

int main() {
	//testBattle();
	testShop();
}

