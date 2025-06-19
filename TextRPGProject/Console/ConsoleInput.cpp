#include "ConsoleInput.h"

int SelectNumber(std::vector<std::string> options)
{
	int select;
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

		if (1 <= select && select <= options.size()) {
			break;
		}
		else {
			std::cout << "잘못된 입력입니다. 다시 입력하세요." << std::endl;
		}
	}
	return select;
}
