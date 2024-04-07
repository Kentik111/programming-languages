#include <iostream>
#include <vector>
using namespace std;

// Функция для подсчёта количества чётных цифр в числе
int evenDigits(int number) {
    int count = 0; // счётчик
    while (number > 0) { // цикл идёт, пока число не обнулится после делений
        int digit = number % 10; // получаем последнюю цифру в виде остатка после деления на 10
        if (digit % 2 == 0) { // если цифра делится на 2 без остатка
            count++; // увеличиваем счётчик на 1
        }
        number /= 10; // делим  число без остатка на 10, чтобы продолжить цикл
    }
    return count; //возвращаем значение счётчика
}

int main() {
    int n;
    cout << "Enter number: ";
    // Ввод количества чисел
    if (!(cin >> n)) { // введен другой символ
        cout << "Do you know what a number is?" << endl; // Сообщение об ошибке
        return 0; // Завершение работы программы
    }
    // Доп. условие - ограничение количества чисел
    if (n > 10) {
        cout << "Too much numbers";
        return 0;
    }

    vector<int> numbers(n); // создание вектора, где будут храниться числа
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {

        if (!(cin >> numbers[i])) { // опечатка в введении чисел
            cout << "Invalid input. Please try again" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        int count = evenDigits(numbers[i]); // вызов функции для каждого введённого числа
        cout << count << " "; // последовательный вывод
    }

    return 0;
}


