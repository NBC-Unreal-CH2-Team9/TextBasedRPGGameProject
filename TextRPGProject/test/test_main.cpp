// 빌드 설정을 'Debug', 'Release'가 아닌 'Test'으로 지정하면, 여기에 있는 main이 실행됩니다.
// 코드를 테스트해야할 일이 있다면, 여기에서 테스트 바랍니다.

#include <iostream>
#include "../Core/GameManager.h"

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

int main() 
{
	GameManager gm;
	
	std::vector<std::string> options;
	options.emplace_back("몬스터 생성");

	// 간단한 입력 구현
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