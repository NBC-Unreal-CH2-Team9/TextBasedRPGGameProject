#include <iostream>

#include "Core/GameManager.h"
#include "Console/ConsoleInput.h"
#include "Console/ConsoleOutput.h"

int main() {
	
	ConsoleOutput::ShowIntro();

	GameManager gameMamager;
	gameMamager.CreateCharacter();
	ConsoleOutput::ShowCharacterStatus(*(gameMamager.GetCharacter()));

	// 캐릭터가 죽을 때 까지 게임 플로우 반복
	while (true) {

		BattleResult result = gameMamager.Battle();

		if (result.isWin) {
			if (result.isBoss) {
				// 보스전투 승리 처리
				break;
			}
			else {
				// 일반 승리 처리
				
				// 필수 기능 [3]
				// 전투 시스템
				// 경험치 누적 100 이상 → 자동 레벨업

				// 필수 기능 [2]
				// 레벨업 효과

				// 필수 기능 [5]
				// 아이템 및 골드 관리
				// 전투에서 이기면 골드를 얻고, 가끔(30% 확률) 아이템이 떨어집니다.
			}
		}
		else {
			// 패배 처리
			break;
		}

		// 도전 기능 [2]
		// 상점 시스템
		// 전투 이후, 방문 여부를 선택
		gameMamager.Shop();
	}

	// 게임 종료 처리
	return 0;
}