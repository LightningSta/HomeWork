#include "main.h"

std::string isPal(std::string what) { // полиндром это такая вещь что он читается одинаково как слево направо так и наоборот, т.е aba будет читаться одинаково как и abba, но вот 1ab не будет
for (int i = 0; i < what.length()/2; i++) { // мы идем до половинны потому что нам нет надобности проверять полностью все слово т.к мы это и так делаем путем сравнения i элемента и вычетанием из размера массива i вел.
		if (what[i] != what[(what.length() - 1) - i]) {// если у нас не встречаются два одинаковых символа  то это не полиндром
			return "false";
		}
	}
	return "true";
}

std::vector<std::string> starterQ2(std::vector<std::string> whats) {
	std::string what = whats[0];// тут 0 потому что у нас больше 1 строки не может быть считано по заданию
	
	return std::vector<std::string>(1, isPal(what));

}