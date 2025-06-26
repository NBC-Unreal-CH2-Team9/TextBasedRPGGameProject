#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Core/GameManager.h"
#include "Console/ConsoleInput.h"
#include "Console/ConsoleOutput.h"

int main() {
	
	srand((unsigned int)time(nullptr));

	ConsoleOutput::ShowIntro();

	// 게임 메뉴
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
	
	// 캐릭터가 죽을 때 까지 게임 플로우 반복
	bool isGameClear = false;
	while (true) {

		ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));
		ConsoleOutput::ShowCharacterGoldAndItem(*(gameMamager.GetCharacter()));
		BattleResult result = gameMamager.Battle();
		if (result.isWin) {
			if (result.battleType == BattleResult::FINAL_BOSS) {
				// 게임 승리
				isGameClear = true;
				break;
			}
		}
		else {
			// 게임 패배
			isGameClear = false;
			break;
		}
		ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));
		ConsoleOutput::ShowCharacterGoldAndItem(*(gameMamager.GetCharacter()));
		gameMamager.Shop();
	}

	if (isGameClear) {
		ConsoleOutput::ShowGameClear();
		ConsoleOutput::ShowCredit();
	}
	else {
		ConsoleOutput::ShowGameOver();
	}

	return 0;
}