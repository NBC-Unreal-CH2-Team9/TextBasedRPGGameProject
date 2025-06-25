癤#include <iostream>
#include <string>
#include <vector>

#include "Core/GameManager.h"
#include "Console/ConsoleInput.h"
#include "Console/ConsoleOutput.h"

int main() {
	
	ConsoleOutput::ShowIntro();

	// 寃 硫
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
	while (true) {

		ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));
		ConsoleOutput::ShowCharacterGoldAndItem(*(gameMamager.GetCharacter()));
		BattleResult result = gameMamager.Battle();
		if (result.isWin) {
			if (result.battleType == BattleResult::FINAL_BOSS) {
				// 蹂댁ㅼ 밸━ 泥由
				break;
			}
		}
		else {
			// ⑤같 泥由
			break;
		}
		ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));
		ConsoleOutput::ShowCharacterGoldAndItem(*(gameMamager.GetCharacter()));
		gameMamager.Shop();
	}

	// 寃 醫猷 泥由
	return 0;
}