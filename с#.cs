using System; // подключение библиотеки для работы с C#
using System.Collections.Generic;  // подключение коллекций (Hash set)
using System.Linq; // подключение методов для работы с коллекциями

class Program
{
    static bool IsPangram(string sentence) // проверка на панграмму
    {
        HashSet<char> letters = new HashSet<char>();

        foreach (char c in sentence) // посимвольно пробегаем строку
        {
            if (char.IsLetter(c)) // если символ является буквой
            {
                letters.Add(char.ToLower(c)); // уменьшаем регистр и добавляем во множество
            }
        }

        return letters.Count == 26; // возвращает истину, если в предложении встречаются все 26 букв английского алфавита
    }

    static void Main()
    {
        Console.Write("Enter sentence: ");
        string sentence = Console.ReadLine(); // ввод строки

        bool englishSymbols = true; // создание флага для проверки на наличие в строке других символов, кроме английских букв и пробела
        foreach (char c in sentence)
        {
            if (!char.IsWhiteSpace(c) && !char.IsLetter(c))
            {
                englishSymbols = false; // если такой сивол находится, флаг меняет значение
                break;
            }
        }

        if (!englishSymbols) // если значение флага - ложь
        {
            Console.WriteLine("The sentence contains invalid characters"); // вывод ошибки
            return; // завершение работы программы
        }

        bool result = IsPangram(sentence); // вызов функции

        Console.WriteLine(result); // вывод результата
    }
}
