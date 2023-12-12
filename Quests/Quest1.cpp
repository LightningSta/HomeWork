#include <iostream>
#include <vector>
#include <string>

std::vector<double> toVec(std::vector<std::string> readVal) { 
	std::vector<double> returnVec;
	for (int i = 0; i < readVal.size(); i++) {
		returnVec.push_back(std::stod(readVal[i])); // stod - string to double ���������� ������ � ����� ���� double ���� ����� ��������

	}
	return returnVec;
}

std::vector<double> sort(std::vector<double> sorting) {
	for (int i = 0; i < sorting.size() - 1; i++) { // ��� -1 �.� �� ����� ������� i � i+1, � ���� �� ������ �� ���������� �������� � ���������� ���������� � ���������� �� ������ ������
		if (sorting[i] > sorting[i+1]) { // ��������� �� �������� � ��������
			std::swap(sorting[i], sorting[i + 1]); // ������ � ��������� ������
			sort(sorting);
		}
	}
	return sorting;
}
std::vector<std::string> toWrite(std::vector<double> sorting) { // �������������� �� �������� toVec
	std::vector<std::string> ret;
	for (int i = 0; i < sorting.size(); i++) {
		ret.push_back(std::to_string(sorting[i]));
	}
	return ret;
}