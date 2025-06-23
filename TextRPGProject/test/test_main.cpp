// 鍮뚮뱶 ?ㅼ젙??'Debug', 'Release'媛 ?꾨땶 'Test'?쇰줈 吏?뺥븯硫? ?ш린???덈뒗 main???ㅽ뻾?⑸땲??
#include <iostream>
#include <string>

#include "../Core/GameManager.h"

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Core/GameManager.h"

int main() {

	std::vector<std::string> input;
	input.push_back("전투");

	GameManager gm;
	gm.CreateCharacter();

	gm.Battle();
	gm.Battle();
	gm.Battle();

	/*while (1)
	{
		switch (SelectNumber(input))
		{
		case 1:
			break;
		case 2:
		
			break;
		}
	}*/




	return 0;
}
