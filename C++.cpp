#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isPangram(const string& sentence) { //������� �������� �� ���������
    set<char> letters; // �������� ��������� ����

    for (char str : sentence) { // ������ �� ������
        if (isalpha(str)) { // �������� �� ������ ������?
            letters.insert(tolower(str)); // ���������� ����� � ���������. ������ ����� ��������, �.�. � ������ ����� ��������� ���������
        }
    }
    return letters.size() == 26; // ������ ������ ���� ������ ���������� ���� � ���������� �������� (� ����������� ������ ����������� ��� �����)
}

int main() {
    string sentence; // ���������� ������
    cout << "Enter sentence: "; // ��������� � ������������
    getline(cin, sentence); // ���� ������,� ����������

    bool englishSymbols = true; // ����
    for (char symbol : sentence) { // ����������� ��������� ������
        if (!isspace(symbol) && !isalpha(symbol)) { // ���� ������ �� ������ � �� ���������� �����
            englishSymbols = false; // ���� ��������
            break; // ���� �����������
        }
    }

    if (!englishSymbols) { // ���� �������� ����� - ����
        cout << "The sentence contains invalid characters" << endl; // "����������� �������� ������������ �������"
        return 0;
    }

    bool result = isPangram(sentence); // �������� ������� � ���������� � ��������� � ���������� result

    if (result) {
        cout << "true" << endl; // ����������� �������� ����������
    }
    else {
        cout << "false" << endl; // ����������� �� �������� ����������
    }

    return 0;
}


