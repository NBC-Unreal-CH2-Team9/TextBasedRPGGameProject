// 빌드 설정을 'Debug', 'Release'가 아닌 'Test'으로 지정하면, 여기에 있는 main이 실행됩니다.
#include <iostream>
<<<<<<< HEAD
#include "../Core/GameManager.h"

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Core/GameManager.h"

<<<<<<< HEAD
int main() 
{
	GameManager gm;
	
	std::vector<std::string> options;
	options.emplace_back("���� ����");
=======
int main() {
>>>>>>> f65649bf6c857c74f3b6030eb438625e0b70b32d

	// ���� �Ŵ��� Ŭ����
	GameManager gameMamager;

<<<<<<< HEAD
	switch (select) {
	case 1:
		//gm.GenerateMonster(1);
		break;
	case 2:
		
		break;
	case 3:
		
		break;
=======
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
>>>>>>> f65649bf6c857c74f3b6030eb438625e0b70b32d
	}

	// ���� ���� ó��
=======
int main() {
>>>>>>> 9552658dbfafaa7c3ce48ede21096655928293d1
	return 0;
}
