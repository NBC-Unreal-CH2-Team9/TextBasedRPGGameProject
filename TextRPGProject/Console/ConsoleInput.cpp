#include "ConsoleInput.h"

int SelectNumber(std::vector<std::string> options)
{
	int select;
	while (true) {
		// ������Ʈ ���
		for (int n = 0; n < options.size(); n++) {
			std::cout << (n + 1) << ": " << options[n];
			if (n != options.size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
		std::cout << "����: ";
		std::cin >> select;

		if (1 <= select && select <= options.size()) {
			break;
		}
		else {
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << std::endl;
		}
	}
	return select;
}

bool SelectYesOrNo(std::string question)
{
	char input;
	while (true) {

		std::cout << question << " [Y/N]: ";
		std::cin >> input;

		if (input == 'Y' || input == 'y') {
			return true;
		}
		else if (input == 'N' || input == 'n') {
			return false;
		}
		else {
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << std::endl;
		}
	}
}
