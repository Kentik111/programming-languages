using System; // ����������� ���������� ��� ������ � C#
using System.Collections.Generic;  // ����������� ��������� (Hash set)
using System.Linq; // ����������� ������� ��� ������ � �����������

class Program
{
    static bool IsPangram(string sentence) // �������� �� ���������
    {
        HashSet<char> letters = new HashSet<char>();

        foreach (char c in sentence) // ����������� ��������� ������
        {
            if (char.IsLetter(c)) // ���� ������ �������� ������
            {
                letters.Add(char.ToLower(c)); // ��������� ������� � ��������� �� ���������
            }
        }

        return letters.Count == 26; // ���������� ������, ���� � ����������� ����������� ��� 26 ���� ����������� ��������
    }

    static void Main()
    {
        Console.Write("Enter sentence: ");
        string sentence = Console.ReadLine(); // ���� ������

        bool englishSymbols = true; // �������� ����� ��� �������� �� ������� � ������ ������ ��������, ����� ���������� ���� � �������
        foreach (char c in sentence)
        {
            if (!char.IsWhiteSpace(c) && !char.IsLetter(c))
            {
                englishSymbols = false; // ���� ����� ����� ���������, ���� ������ ��������
                break;
            }
        }

        if (!englishSymbols) // ���� �������� ����� - ����
        {
            Console.WriteLine("The sentence contains invalid characters"); // ����� ������
            return; // ���������� ������ ���������
        }

        bool result = IsPangram(sentence); // ����� �������

        Console.WriteLine(result); // ����� ����������
    }
}
