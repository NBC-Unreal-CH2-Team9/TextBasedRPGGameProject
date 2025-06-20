// ���� ������ 'Debug', 'Release'�� �ƴ� 'Test'���� �����ϸ�, ���⿡ �ִ� main�� ����˴ϴ�.
// �ڵ带 �׽�Ʈ�ؾ��� ���� �ִٸ�, ���⿡�� �׽�Ʈ �ٶ��ϴ�.

#include <iostream>

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Core/GameManager.h"

int main() {

	// ���� �Ŵ��� Ŭ����
	GameManager gameMamager;

	// �ʼ� ������κ���, ������ �����ؾ� �ϴ��� �̾Ƴ��� ������ �ؾ� �մϴ�.
	// �Ʒ��� �����Դϴ�.

	// �ʼ� ��� [1]
	// ĳ���� ���� �� ����
	// ���ϴ� �̸����� ĳ���͸� �ϳ� ��! ���� �� �־�� �մϴ�.
	// -> �̸��� �Է¹޾� ĳ���� ����
	// ���� 1, �ʱ� ü�� 200, ���ݷ� 30, ����ġ 0���� �����ϰ�, �������� �ʿ��� ����ġ�� 100 ����!
	// -> ĳ���� Ŭ������ ������ �� ������Ƽ(�������)�� �ʱⰪ ��
	// �������� ĳ���� ���� Ȯ�� ����!
	// -> ���¸� Ȯ���ϴ� ����� �����ؾ� ��

	/* ĳ���� ���� �κ� */
	/* �ʿ��ϸ� return type �߰� Type a = */
	gameMamager.CreateCharacter(/*�ʿ��ϸ� parameter �߰�*/);

	// ĳ���Ͱ� ���� �� ���� ���� �÷ο� �ݺ�
	// while (!character->IsDead()) { ... }
	while (true) {

		// �ʼ� ��� [3]
		// ���� �ý���
		// ĳ���� ���� ����, �׸��� ���� �湮(�Ǵ� ��ŵ) ����
		gameMamager.GetCharacter()->DisplayStatus();

		BattleResult result = gameMamager.Battle();

		if (true) {
			if (result.isBoss) {
				// �������� �¸� ó��
				break;
			}
			else {
				// �Ϲ� �¸� ó��

				// �ʼ� ��� [3]
				// ���� �ý���
				// ����ġ ���� 100 �̻� �� �ڵ� ������


				// �ʼ� ��� [2]
				// ������ ȿ��
				for (int i = 0; i < 10; i++) {
					gameMamager.GetCharacter()->LevelUp();
					gameMamager.GetCharacter()->DisplayStatus();
				}
				


				break;

				// �ʼ� ��� [5]
				// ������ �� ��� ����
				// �������� �̱�� ��带 ���, ����(30% Ȯ��) �������� �������ϴ�.
			}
		}
		else {
			// �й� ó��
			break;
		}

		// ���� ��� [2]
		// ���� �ý���
		// ���� ����, �湮 ���θ� ����
		// gameMamager.Shop();
	}

	// ���� ���� ó��
	return 0;
}