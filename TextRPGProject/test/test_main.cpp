// 빌드 설정을 'Debug', 'Release'가 아닌 'Test'으로 지정하면, 여기에 있는 main이 실행됩니다.
// 코드를 테스트해야할 일이 있다면, 여기에서 테스트 바랍니다.

#include <iostream>

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

int main() {
	
	std::vector<std::string> options;
	options.emplace_back("사과");
	options.emplace_back("바나나");
	options.emplace_back("배");

	// 간단한 입력 구현
	int select = SelectNumber(options);

	switch (select) {
	case 1:
		std::cout << "사과는 빨개" << std::endl;
		break;
	case 2:
		std::cout << "바나나는 길어" << std::endl;
		break;
	case 3:
		std::cout << "나주배" << std::endl;
		break;
	}
	return 0;
}