// prakex2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

string sum(string num1, string num2)                                                // Функция суммирования
{
    bool flag = false;
    string summa, num_a, num_b;
    int summa_a_b, m;
    int len, diff = 0;
    len = num1.size();                                                              // Смотрим длину и разницу в знаках, для того чтобы не выйти за предел меньшего
    diff = num1.size() - num2.size();
    for (int i = 1; i <= len; i++)                      
    {
        num_a = "0";
        num_b = "0";
        num_a = num1[len - i];
        if (len - i - diff > -1)
        {
            num_b = num2[len - i - diff];
        }
        if (flag)                                                                  // Если при сложении получился переход на следующий разряд, то мы добавляем 1
        {
            summa_a_b = stoi(num_a) + stoi(num_b) + 1;
            flag = false;
        }
        else
        {
            summa_a_b = stoi(num_a) + stoi(num_b);
        }
        if (summa_a_b > 9)
        {
            flag = true;
            summa_a_b -= 10;
        }
        summa = to_string(summa_a_b) + summa;

    }
    if (flag)
    {
        summa = '1' + summa;
        flag = false;
    }
    return summa;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    string num1, num2, summa, c = "1";
    cin >> num1 >> num2;
    if (num1.size() < num2.size()) {
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }
    cout << "Сумма: " << sum(num1, num2) << std::endl;
    summa = num1;
    while (c != num2)
    {
        summa = sum(summa, num1);
        c = sum(c, "1");
    }
    cout << "Произведение: " << summa;
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
