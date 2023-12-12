#include "main.h"


std::vector<std::string> split(std::string charIs, std::string what) {
	std::vector<std::string> returns; 
	std::string adding = "";// строка которая получится до встречи с charIs
	for (int i = 0; i < what.size(); i++) {
		std::string newx = "";
		newx += what[i];
		if (newx == charIs) { // проверка что за символ
			returns.push_back(adding);
			adding = "";
		}
		else {
			adding += newx;
		}
	}
	if (adding.length() > 1) { // в конце может получится что строка закончилась, а мы не встретили нужный символ, а это значит что нам нужно добавить остаток тоже как результат.
		returns.push_back(adding);
	}
	return returns;
}

int countString(std::string charIs, std::vector<std::string> whats) {
	int founded = 0;
	for (int i = 0; i < whats.size(); i++) {
		if (whats[i] == charIs) {
			founded += 1;
		}

	}
	return founded;
}
/*
		Данная функция аналогична, 3 задания только вместо символов у нас слова и много строк поэтому мы делаем одну строку(для удобства) и делим строку по пробелам
	
*/


std::vector<std::string> starterQ4(std::vector<std::string> whats) { 
	std::string what = "";
	for (std::string s : whats) {
		std::vector<std::string> returnsa = split(".", s);
		std::string ds = "";
		for (int i = 0; i < returnsa.size(); i++) {
			ds += returnsa[i];
		}
		returnsa = split(",", ds);
		ds = "";
		for (int i = 0; i < returnsa.size(); i++) {
			ds += returnsa[i];
		}
		what += ds + " ";
	}
	std::set<std::string> charss = toSet(split(" ", what));
	std::vector<int> resultsNumber;
	std::string result = "";
	for (int i = 0; i < charss.size(); i++) {
		int j = 0;
		std::string ps;
		for (std::string s : charss) {
			if (j == i) {
				ps = s;
				break;
			}
			j++;
		}
		resultsNumber.push_back(countString(ps, split(" ", what)));
	}
	int maximumm = maximum(resultsNumber);
	int j = 0;
	for (std::string s : charss) {
		if (j == vecFound(resultsNumber, maximumm)) {
			result = s + " " + std::to_string(maximumm);
			break;
		}
		j++;
	}
	return std::vector<std::string>(1, result);

}