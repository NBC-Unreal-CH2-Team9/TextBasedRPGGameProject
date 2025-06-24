#include <iostream>

#include "Core/GameManager.h"
#include "Console/ConsoleInput.h"
#include "Console/ConsoleOutput.h"

int main() {
	
	ConsoleOutput::ShowIntro();

	GameManager gameMamager;
	gameMamager.CreateCharacter();
	ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));

	// ĳ���Ͱ� ���� �� ���� ���� �÷ο� �ݺ�
	while (true) {

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

		// ���� ��� [2]
		// ���� �ý���
		// ���� ����, �湮 ���θ� ����
		gameMamager.Shop();
	}

	// ���� ���� ó��
	return 0;
}