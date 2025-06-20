#include "GameManager.h"

GameManager::GameManager()
{
	character == nullptr;
}

GameManager::~GameManager()
{
	if (character != nullptr) {
		delete character;
	}
}

void GameManager::CreateCharacter()
{
}

BattleResult GameManager::Battle()
{
	// 필수 기능 [3]
	// 전투 시스템
	// 캐릭터 생성 직후, 그리고 상점 방문(또는 스킵) 이후

	// 필수 기능 [4]
	// 몬스터 설명

	// 전투 로직
	// 전투 로직 담당자가 구현
	// while () {
	// ...
	// }

	BattleResult result;
	result.isWin = false;
	result.isBoss = false;
	return result;
}

void GameManager::Shop()
{
}
