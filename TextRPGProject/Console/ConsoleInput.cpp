#include "ConsoleInput.h"

int SelectNumber(std::vector<std::string> options)
{
	std::string select;
	while (true) {
		// 프롬프트 출력
		for (int n = 0; n < options.size(); n++) {
			std::cout << (n + 1) << ": " << options[n];
			if (n != options.size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
		std::cout << "선택: ";
		std::cin >> select;

		int number = std::stoi(select);

		if (1 <= number && number <= options.size()) {
			return number - 1;
		}
		else {
			std::cout << "잘못된 입력입니다. 다시 입력하세요." << std::endl;
		}
	}
	return -1;
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
			std::cout << "잘못된 입력입니다. 다시 입력하세요." << std::endl;
		}
	}
}
