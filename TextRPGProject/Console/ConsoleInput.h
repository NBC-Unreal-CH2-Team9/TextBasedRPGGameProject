#pragma once
#include <string>
#include <iostream>
#include <vector>

// options = ["���", "�ٳ���", "��"] �� ��,
// ȭ�鿡 ������ ����ϰ�, ���� �Է��� �޴´�.
// �ùٸ� �Է��� ������, �� ���ڸ� ��ȯ�Ѵ�.
// �߸��� �Է��� ������, �ùٸ� �Է��� ���� �� ���� �ݺ��Ѵ�.
// ����ڴ� [1, N]�� �Է��ϰ�, ����� [0, N-1]�� ��ȯ�Ѵ�.
int SelectNumber(std::vector<std::string> options);

// Y/N �Է�
bool SelectYesOrNo(std::string question);