#include "main.h"

std::string isPal(std::string what) { // ��������� ��� ����� ���� ��� �� �������� ��������� ��� ����� ������� ��� � ��������, �.� aba ����� �������� ��������� ��� � abba, �� ��� 1ab �� �����
for (int i = 0; i < what.length()/2; i++) { // �� ���� �� ��������� ������ ��� ��� ��� ���������� ��������� ��������� ��� ����� �.� �� ��� � ��� ������ ����� ��������� i �������� � ���������� �� ������� ������� i ���.
		if (what[i] != what[(what.length() - 1) - i]) {// ���� � ��� �� ����������� ��� ���������� �������  �� ��� �� ���������
			return "false";
		}
	}
	return "true";
}

std::vector<std::string> starterQ2(std::vector<std::string> whats) {
	std::string what = whats[0];// ��� 0 ������ ��� � ��� ������ 1 ������ �� ����� ���� ������� �� �������
	
	return std::vector<std::string>(1, isPal(what));

}