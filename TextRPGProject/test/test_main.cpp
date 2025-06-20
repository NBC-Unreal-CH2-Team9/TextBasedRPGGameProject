// 빌드 설정을 'Debug', 'Release'가 아닌 'Test'으로 지정하면, 여기에 있는 main이 실행됩니다.
// 코드를 테스트해야할 일이 있다면, 여기에서 테스트 바랍니다.

#include <iostream>

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Core/GameManager.h"

int main() {

	// 게임 매니저 클래스
	GameManager gameMamager;

	// 필수 기능으로부터, 무엇을 구현해야 하는지 뽑아내는 연습을 해야 합니다.
	// 아래는 예시입니다.

	// 필수 기능 [1]
	// 캐릭터 생성 및 관리
	// 원하는 이름으로 캐릭터를 하나 뿅! 만들 수 있어야 합니다.
	// -> 이름을 입력받아 캐릭터 생성
	// 레벨 1, 초기 체력 200, 공격력 30, 경험치 0으로 시작하고, 레벨업에 필요한 경험치는 100 고정!
	// -> 캐릭터 클래스가 가져야 할 프로퍼티(멤버변수)와 초기값 등
	// 언제든지 캐릭터 상태 확인 가능!
	// -> 상태를 확인하는 기능을 구현해야 함

	/* 캐릭터 생성 부분 */
	/* 필요하면 return type 추가 Type a = */
	gameMamager.CreateCharacter(/*필요하면 parameter 추가*/);

	// 캐릭터가 죽을 때 까지 게임 플로우 반복
	// while (!character->IsDead()) { ... }
	while (true) {

		// 필수 기능 [3]
		// 전투 시스템
		// 캐릭터 생성 직후, 그리고 상점 방문(또는 스킵) 이후
		gameMamager.GetCharacter()->DisplayStatus();

		BattleResult result = gameMamager.Battle();

		if (true) {
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
				for (int i = 0; i < 10; i++) {
					gameMamager.GetCharacter()->LevelUp();
					gameMamager.GetCharacter()->DisplayStatus();
				}
				


				break;

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
		// gameMamager.Shop();
	}

	// 게임 종료 처리
	return 0;
}