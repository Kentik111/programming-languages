#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isPangram(const string& sentence) { //Функция проверки на панграмму
    set<char> letters; // создание множества букв

    for (char str : sentence) { // пробег по строке
        if (isalpha(str)) { // является ли символ буквой?
            letters.insert(tolower(str)); // добавление буквы в множество. Делаем букву строчной, т.к. в строке могут попасться заглавные
        }
    }
    return letters.size() == 26; // размер должен быть равным количеству букв в английском алфавите (в предложении должны встретиться все буквы)
}

int main() {
    string sentence; // объявление строки
    cout << "Enter sentence: "; // обращение к пользователю
    getline(cin, sentence); // ввод строки,её считывание

    bool englishSymbols = true; // флаг
    for (char symbol : sentence) { // посимвольно пробегаем строку
        if (!isspace(symbol) && !isalpha(symbol)) { // если символ не пробел и не английская буква
            englishSymbols = false; // флаг меняется
            break; // цикл прерывается
        }
    }

    if (!englishSymbols) { // Если значение флага - ложь
        cout << "The sentence contains invalid characters" << endl; // "Предложение содержит недопустимые символы"
        return 0;
    }

    bool result = isPangram(sentence); // вызываем функцию и записываем её результат в переменную result

    if (result) {
        cout << "true" << endl; // предложение является панграммой
    }
    else {
        cout << "false" << endl; // предложение не является панграммой
    }

    return 0;
}


