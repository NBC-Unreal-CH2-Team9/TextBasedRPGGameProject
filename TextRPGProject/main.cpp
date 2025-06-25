#include <iostream>
#include <string>
#include <vector>

#include "Core/GameManager.h"
#include "Console/ConsoleInput.h"
#include "Console/ConsoleOutput.h"

int main() {
	
	ConsoleOutput::ShowIntro();

	// ���� �޴�
	while (true) {
		std::vector<std::string> menu = { "GAME START", "CREDITS", "EXIT" };
		int menuSelect = ConsoleInput::SelectNumberVertical(menu);
		
		if (menuSelect == 0) {
			break;
		}
		else if (menuSelect == 1) {
			ConsoleOutput::ShowCredit();
			continue;
		}
		else if (menuSelect == 2) {
			return 0;
		}
	}

	GameManager gameMamager;
	gameMamager.CreateCharacter();
	
	// ĳ���Ͱ� ���� �� ���� ���� �÷ο� �ݺ�
	while (true) {

		ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));
		ConsoleOutput::ShowCharacterGoldAndItem(*(gameMamager.GetCharacter()));
		BattleResult result = gameMamager.Battle();
		if (result.isWin) {
			if (result.isBoss) {
				// �������� �¸� ó��
				break;
			}
		}
		else {
			// �й� ó��
			break;
		}
		ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));
		ConsoleOutput::ShowCharacterGoldAndItem(*(gameMamager.GetCharacter()));
		gameMamager.Shop();
	}

	// ���� ���� ó��
	return 0;
}