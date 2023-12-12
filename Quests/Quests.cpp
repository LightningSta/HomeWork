#include "main.h" //Добавляем все что нам понадобится 
#include "Quest1.cpp" // Подключаем файл с решением
#include "Quest2.cpp"
#include "Quest3.cpp"
#include "Quest4.cpp"
#include "Quest5.cpp"





std::vector<std::string> fileReader(std::string path) {
    std::ifstream fileRead; //Мы подключаемся к потоку для чтения
    fileRead.open(path); // Открываем ссылку на файл
    std::vector<std::string> outVal; // Создаем вектор(место где будут лежать все считанные строки) 
    while (fileRead) { //пока есть что читать читаем
        std::string s;
        std::getline(fileRead, s);//получаем строку из потока данных
        if (s.size()>0) {
            outVal.push_back(s);
        }
    }
    fileRead.close();// закрываем файл
    return outVal;// возвращаем считывание


}
void fileWriter(std::string name, std::vector<std::string> r) {
    std::ofstream fileWrite("uploads\\"+name + ".txt"); //путь куда будут сохраняться файлы
    for (int i = 0; i < r.size(); i++) {
        fileWrite << r[i] << "\n"; // записываем строку и заканчиваем через \n
    }
    fileWrite.close(); // закрываем файл


}

void printVec(std::vector<double> d) {
    for (int i = 0; i < d.size(); i++) {
        std::cout << d[i] << "\n";
    }
}


int main()
{
    fileWriter("QuestComplete1", toWrite(sort(toVec(fileReader("Files/Quest1.txt"))))); 
    fileWriter("QuestComplete2", starterQ2(fileReader("Files/Quest2.txt")));
    fileWriter("QuestComplete3", starterQ3(fileReader("Files/Quest3.txt")));
    fileWriter("QuestComplete4", starterQ4(fileReader("Files/Quest4.txt")));
    fileWriter("QuestComplete5", starterQ5(fileReader("Files/Quest5.txt")));
}
