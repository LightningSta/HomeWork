#include "main.h"


/*

		Аналогично 4 номеру за исключением, что мы не выбераем лучшего, а добавляем всех


*/

std::vector<std::string> starterQ5(std::vector<std::string> whats) {
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
			ds += returnsa[i] ;
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
	int j = 0;
	std::vector<std::string> results;
	int sum = 0;
	for (int i = 0; i < resultsNumber.size(); i++) {
		sum += resultsNumber[i];
	}
	results.push_back(std::to_string(sum));
	for (std::string s : charss) {
		result = s + ": " + std::to_string(resultsNumber[j]);
		results.push_back(result);
		result = "";
		j++;
	}
	return results;

}