// ���� ������ 'Debug', 'Release'�� �ƴ� 'Test'���� �����ϸ�, ���⿡ �ִ� main�� ����˴ϴ�.
// �ڵ带 �׽�Ʈ�ؾ��� ���� �ִٸ�, ���⿡�� �׽�Ʈ �ٶ��ϴ�.

#include <iostream>
#include "../Core/GameManager.h"

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

int main() 
{
	GameManager gm;
	
	std::vector<std::string> options;
	options.emplace_back("���� ����");

	// ������ �Է� ����
	int select = SelectNumber(options);

	switch (select) {
	case 1:
		//gm.GenerateMonster(1);
		break;
	case 2:
		
		break;
	case 3:
		
		break;
	}
	return 0;
}