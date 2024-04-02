import java.util.Scanner; //подключение сканнера, который считывает данные

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // подключение параметра System к сканеру
        System.out.print("Enter Number: ");
        int N = input.nextInt();
        if (N > 26) { // если введено число, большее размера английского алфавита
            System.out.println("Error"); // Ошибка
            return; // завершение программы
        }

        for (int i = 0; i < N; i++) { //пробег индексов от 0 до заданного N
            char this_Char = (char)('A' + N - 1); // конечная буква
            for (int j = 0; j <= i; j++) { // пробег индексов от 0 до i
                System.out.print(this_Char + " "); // вывод букв через пробел
                this_Char--; //смена буквы (иначе будет выводиться одна и та же буква)
            }
            System.out.println(); // переход на новую строку
        }
    }
}


