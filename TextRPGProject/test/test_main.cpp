// ���� ������ 'Debug', 'Release'�� �ƴ� 'Test'���� �����ϸ�, ���⿡ �ִ� main�� ����˴ϴ�.
// �ڵ带 �׽�Ʈ�ؾ��� ���� �ִٸ�, ���⿡�� �׽�Ʈ �ٶ��ϴ�.

#include <iostream>

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

int main() {
	
	std::vector<std::string> options;
	options.emplace_back("���");
	options.emplace_back("�ٳ���");
	options.emplace_back("��");

	// ������ �Է� ����
	int select = SelectNumber(options);

	switch (select) {
	case 1:
		std::cout << "����� ����" << std::endl;
		break;
	case 2:
		std::cout << "�ٳ����� ���" << std::endl;
		break;
	case 3:
		std::cout << "���ֹ�" << std::endl;
		break;
	}
	return 0;
}