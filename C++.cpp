#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Enter number: ";
    cin >> N; // ввод числа
    if (N > 26){ // если введено число, большее размера английского алфавита
        cout << "Error" << endl; // Ошибка
        return 0; // завершение программы
    }

    for (int i = 0; i < N; i++) { // пробег индексов от 0 до заданного N
        char this_Char = 'A' + N - 1; // конечная буква
        for (int j = 0; j <= i; j++) { // пробег индексов от 0 до i
            cout << this_Char << " "; // вывод букв через пробел
            this_Char--; //смена буквы (без этой команды будет выводиться одна и та же буква)
        }
        cout << endl; // переход на новую строку
    }

    return 0;
}
