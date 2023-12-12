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
		max = std::max(vec[i], max);//если max больше vec[i] то он и не изментся
	}
	return max;
}

std::set<std::string> toSet(std::vector<std::string> vec) { // set это аналог вектора, но только в нем могут лежать только уникальные значения
	std::set<std::string> sets;
	if (vec.size() == 1) {
		for (int j = 0; j < vec[0].size(); j++) { // Для случая если нам нужно у строки взять все уникальные символы
			std::string s = "";
			s += vec[0][j]; // char сами по себе представляют собой значения в кодировке  ASCII  поэтому если мы просто добавим в set то у нас будет число, а данная конструкция призвана избежать этого 
			sets.insert(s);
		}
	}
	else {
		for (int j = 0; j < vec.size(); j++) { // Для случая если нам нужно у строк взять все уникальные слова
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
		std::string news(1, what[i]);//аналог создания строки из символа
		if (news == charIs) {
			founded += 1;
		}

	}
	return founded;
}

std::vector<std::string> starterQ3(std::vector<std::string> whats) {
	std::string what = whats[0];// нам дана только одна строчка
	std::set<std::string> charss=toSet(whats);// все уникальные символы в строке
	std::vector<int> resultsNumber;// колличество символов в строке
	std::string result = "";// строка с результатом
	for (int i = 0; i < charss.size(); i++) {
		int j = 0;
		std::string ps; // т.к set не предоставляет эффективное обращение к своим элементам то мы через цикл пройдемся и найдем строку которая нам нужна
		for (std::string s : charss) {
			if (j == i) {
				ps = s;
				break;
			}
			j++;
		}
		resultsNumber.push_back(countS(ps, what)); // добавляем колличество символов
	}
	int maximumm = maximum(resultsNumber); // найдем максимальное колличество
	int j = 0;
	for (std::string s : charss) {
		if (j == vecFound(resultsNumber, maximumm)) {  // найдем символ который соотвествует максимальному колличеству
			result = s + " " + std::to_string(maximumm);
			break;
		}
		j++;
	}
	return std::vector<std::string> (1,result); // создадим вектор из одной строки с результатомы

}