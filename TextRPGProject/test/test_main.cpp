// ���� ������ 'Debug', 'Release'�� �ƴ� 'Test'���� �����ϸ�, ���⿡ �ִ� main�� ����˴ϴ�.
// �ڵ带 �׽�Ʈ�ؾ��� ���� �ִٸ�, ���⿡�� �׽�Ʈ �ٶ��ϴ�.

#include <iostream>

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Core/GameManager.h"

int main() {
	
	GameManager gameMamager;
	gameMamager.CreateCharacter(/*�ʿ��ϸ� parameter �߰�*/);

	gameMamager.GetCharacter()->DisplayStatus();

	return 0;
}