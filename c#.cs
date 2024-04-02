using System; // подключение библиотеки для работы с C#

class Program // 
{
    static void Main()
    {
        Console.Write("Enter number: ");
        int N = int.Parse(Console.ReadLine()); //ввод числа
        if (N > 26){ // если введено число, большее размера английского алфавита
            Console.WriteLine("Error"); // Ошибка
            return; // Завершение программы
        }
        for (int i = 0; i < N; i++) // пробег индексов от 0 до заданного N
        {
            char this_Char = (char)('A' + N - 1); // конечная буква
            for (int j = 0; j <= i; j++) // пробег индексов от 0 до i
            {
                Console.Write(this_Char + " "); // вывод букв через пробел
                this_Char--; //смена буквы (иначе будет выводиться одна и та же буква)
            }
            Console.WriteLine(); // переход на новую строку
        }
    }
}


