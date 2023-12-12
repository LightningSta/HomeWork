#include "main.h"
int vecFound(std::vector<int> vec, int elem) { 
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == elem) {
			return i;
		}
	}
}
int maximum(std::vector<int> vec) {
	int max = -1000000000;
	for (int i = 0; i < vec.size(); i++) {
		max = std::max(vec[i], max);//���� max ������ vec[i] �� �� � �� ��������
	}
	return max;
}

std::set<std::string> toSet(std::vector<std::string> vec) { // set ��� ������ �������, �� ������ � ��� ����� ������ ������ ���������� ��������
	std::set<std::string> sets;
	if (vec.size() == 1) {
		for (int j = 0; j < vec[0].size(); j++) { // ��� ������ ���� ��� ����� � ������ ����� ��� ���������� �������
			std::string s = "";
			s += vec[0][j]; // char ���� �� ���� ������������ ����� �������� � ���������  ASCII  ������� ���� �� ������ ������� � set �� � ��� ����� �����, � ������ ����������� �������� �������� ����� 
			sets.insert(s);
		}
	}
	else {
		for (int j = 0; j < vec.size(); j++) { // ��� ������ ���� ��� ����� � ����� ����� ��� ���������� �����
			std::string s = "";
			s += vec[j];
			sets.insert(s);
		}
	}
	return sets;
}


int countS(std::string charIs, std::string what) {
	int founded = 0;
	for (int i = 0; i < what.length(); i++) {
		std::string news(1, what[i]);//������ �������� ������ �� �������
		if (news == charIs) {
			founded += 1;
		}

	}
	return founded;
}

std::vector<std::string> starterQ3(std::vector<std::string> whats) {
	std::string what = whats[0];// ��� ���� ������ ���� �������
	std::set<std::string> charss=toSet(whats);// ��� ���������� ������� � ������
	std::vector<int> resultsNumber;// ����������� �������� � ������
	std::string result = "";// ������ � �����������
	for (int i = 0; i < charss.size(); i++) {
		int j = 0;
		std::string ps; // �.� set �� ������������� ����������� ��������� � ����� ��������� �� �� ����� ���� ��������� � ������ ������ ������� ��� �����
		for (std::string s : charss) {
			if (j == i) {
				ps = s;
				break;
			}
			j++;
		}
		resultsNumber.push_back(countS(ps, what)); // ��������� ����������� ��������
	}
	int maximumm = maximum(resultsNumber); // ������ ������������ �����������
	int j = 0;
	for (std::string s : charss) {
		if (j == vecFound(resultsNumber, maximumm)) {  // ������ ������ ������� ������������ ������������� �����������
			result = s + " " + std::to_string(maximumm);
			break;
		}
		j++;
	}
	return std::vector<std::string> (1,result); // �������� ������ �� ����� ������ � ������������

}