#pragma once
#include <string>
#include <iostream>
#include <vector>

// options = ["사과", "바나나", "배"] 일 때,
// 화면에 다음을 출력하고, 숫자 입력을 받는다.
// 올바른 입력을 받으면, 그 숫자를 반환한다.
// 잘못된 입력을 받으면, 올바른 입력을 받을 때 까지 반복한다.
int SelectNumber(std::vector<std::string> options);
