#include <iostream>
#include <vector>
#include <string>

std::vector<double> toVec(std::vector<std::string> readVal) { 
	std::vector<double> returnVec;
	for (int i = 0; i < readVal.size(); i++) {
		returnVec.push_back(std::stod(readVal[i])); // stod - string to double превращает строку в число типа double если такое возможно

	}
	return returnVec;
}

std::vector<double> sort(std::vector<double> sorting) {
	for (int i = 0; i < sorting.size() - 1; i++) { // шаг -1 т.к мы берем элемент i и i+1, а если мы дойдем до последнего элемента и попытаемся обратиться к следующему он выдаст ошибку
		if (sorting[i] > sorting[i+1]) { // сортируем от меньшего к большему
			std::swap(sorting[i], sorting[i + 1]); // меняем и запускаем заново
			sort(sorting);
		}
	}
	return sorting;
}
std::vector<std::string> toWrite(std::vector<double> sorting) { // противоположен по действию toVec
	std::vector<std::string> ret;
	for (int i = 0; i < sorting.size(); i++) {
		ret.push_back(std::to_string(sorting[i]));
	}
	return ret;
}