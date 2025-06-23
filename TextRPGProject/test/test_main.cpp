// ë¹Œë“œ ì„¤ì •ì„ 'Debug', 'Release'ê°€ ì•„ë‹Œ 'Test'ìœ¼ë¡œ ì§€ì •í•˜ë©´, ì—¬ê¸°ì— ìˆëŠ” mainì´ ì‹¤í–‰ë©ë‹ˆë‹¤.
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
	options.emplace_back("¸ó½ºÅÍ »ı¼º");
=======
int main() {
>>>>>>> f65649bf6c857c74f3b6030eb438625e0b70b32d

	// °ÔÀÓ ¸Å´ÏÀú Å¬·¡½º
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
	// ÇÊ¼ö ±â´ÉÀ¸·ÎºÎÅÍ, ¹«¾ùÀ» ±¸ÇöÇØ¾ß ÇÏ´ÂÁö »Ì¾Æ³»´Â ¿¬½ÀÀ» ÇØ¾ß ÇÕ´Ï´Ù.
	// ¾Æ·¡´Â ¿¹½ÃÀÔ´Ï´Ù.

	// ÇÊ¼ö ±â´É [1]
	// Ä³¸¯ÅÍ »ı¼º ¹× °ü¸®
	// ¿øÇÏ´Â ÀÌ¸§À¸·Î Ä³¸¯ÅÍ¸¦ ÇÏ³ª »Ğ! ¸¸µé ¼ö ÀÖ¾î¾ß ÇÕ´Ï´Ù.
	// -> ÀÌ¸§À» ÀÔ·Â¹Ş¾Æ Ä³¸¯ÅÍ »ı¼º
	// ·¹º§ 1, ÃÊ±â Ã¼·Â 200, °ø°İ·Â 30, °æÇèÄ¡ 0À¸·Î ½ÃÀÛÇÏ°í, ·¹º§¾÷¿¡ ÇÊ¿äÇÑ °æÇèÄ¡´Â 100 °íÁ¤!
	// -> Ä³¸¯ÅÍ Å¬·¡½º°¡ °¡Á®¾ß ÇÒ ÇÁ·ÎÆÛÆ¼(¸â¹öº¯¼ö)¿Í ÃÊ±â°ª µî
	// ¾ğÁ¦µçÁö Ä³¸¯ÅÍ »óÅÂ È®ÀÎ °¡´É!
	// -> »óÅÂ¸¦ È®ÀÎÇÏ´Â ±â´ÉÀ» ±¸ÇöÇØ¾ß ÇÔ

	/* Ä³¸¯ÅÍ »ı¼º ºÎºĞ */
	/* ÇÊ¿äÇÏ¸é return type Ãß°¡ Type a = */
	gameMamager.CreateCharacter(/*ÇÊ¿äÇÏ¸é parameter Ãß°¡*/);

	// Ä³¸¯ÅÍ°¡ Á×À» ¶§ ±îÁö °ÔÀÓ ÇÃ·Î¿ì ¹İº¹
	// while (!character->IsDead()) { ... }
	while (true) {

		// ÇÊ¼ö ±â´É [3]
		// ÀüÅõ ½Ã½ºÅÛ
		// Ä³¸¯ÅÍ »ı¼º Á÷ÈÄ, ±×¸®°í »óÁ¡ ¹æ¹®(¶Ç´Â ½ºÅµ) ÀÌÈÄ
		gameMamager.GetCharacter()->DisplayStatus();

		BattleResult result = gameMamager.Battle();

		if (true) {
			if (result.isBoss) {
				// º¸½ºÀüÅõ ½Â¸® Ã³¸®
				break;
			}
			else {
				// ÀÏ¹İ ½Â¸® Ã³¸®

				// ÇÊ¼ö ±â´É [3]
				// ÀüÅõ ½Ã½ºÅÛ
				// °æÇèÄ¡ ´©Àû 100 ÀÌ»ó ¡æ ÀÚµ¿ ·¹º§¾÷


				// ÇÊ¼ö ±â´É [2]
				// ·¹º§¾÷ È¿°ú
				for (int i = 0; i < 10; i++) {
					gameMamager.GetCharacter()->LevelUp();
					gameMamager.GetCharacter()->DisplayStatus();
				}
				


				break;

				// ÇÊ¼ö ±â´É [5]
				// ¾ÆÀÌÅÛ ¹× °ñµå °ü¸®
				// ÀüÅõ¿¡¼­ ÀÌ±â¸é °ñµå¸¦ ¾ò°í, °¡²û(30% È®·ü) ¾ÆÀÌÅÛÀÌ ¶³¾îÁı´Ï´Ù.
			}
		}
		else {
			// ÆĞ¹è Ã³¸®
			break;
		}

		// µµÀü ±â´É [2]
		// »óÁ¡ ½Ã½ºÅÛ
		// ÀüÅõ ÀÌÈÄ, ¹æ¹® ¿©ºÎ¸¦ ¼±ÅÃ
		// gameMamager.Shop();
>>>>>>> f65649bf6c857c74f3b6030eb438625e0b70b32d
	}

	// °ÔÀÓ Á¾·á Ã³¸®
=======
int main() {
>>>>>>> 9552658dbfafaa7c3ce48ede21096655928293d1
	return 0;
}
