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
	// �ʼ� ��� [3]
	// ���� �ý���
	// ĳ���� ���� ����, �׸��� ���� �湮(�Ǵ� ��ŵ) ����

	// �ʼ� ��� [4]
	// ���� ����

	// ���� ����
	// ���� ���� ����ڰ� ����
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
