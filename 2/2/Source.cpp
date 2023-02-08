#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Exception // Родительский класс Ошибка (Выводит на экран ссобщение об ошибке)
{
public:
    string E_error; // Единственная переменная с текстом об ошибке
    Exception() : E_error("\n Обнаружена ошибка: ") {};
    virtual const string GetError() = 0;
};


class DevZero : public Exception // (Конкретезирует ошибку - Деление на 0)
{
public:
    string Z_error; // Переменная со специализированным выводом ошибки
    DevZero() : Z_error("Деление на ноль !!!") { }
    virtual const string GetError() override
    {
        return E_error + Z_error;
    }
};

class MemErr : public Exception // (Конкретезирует ошибку - Переполнение массива)
{
public:
    string M_error; // Переменная со специализированным выводом ошибки
    MemErr() : M_error("Переполнение масива !!!") { }
    virtual const string GetError() override
    {
        return E_error + M_error;
    }
};

class FileOpErr : public Exception // (Конкретезирует ошибку - Переполнение массива)
{
public:
    string F_error; // Переменная со специализированным выводом ошибки
    FileOpErr() : F_error("Не удалось открыть файл !!!") { }
    virtual const string GetError() override
    {
        return E_error + F_error;
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
 
    int a, b;
    char ch = '4';



    while (ch != '0')
    {
        cout << "\n 0 - Выход";
        cout << "\n 1 - Проверка попытки деления a на b (5 на 0)";
        cout << "\n 2 - Проверка открытия файла (по заданному пути) ";
        cout << "\n 3 - Проверка открытия файла (по заданному пути) ";
        cout << "\n     Выберите проверку исключения для возможных ошибок: ";
        cin >> ch;
        cout << endl << endl;

        try
        {
            if (ch == '1')
            {
                a = 5; // Предупреждение о делении на 0
                b = 0;

                if (b == 0) throw DevZero();
                int c = a / b;
            }

            else if (ch == '2')
            {
                cout << "\n Проверка недостатка памяти (7 элемент не входит в массив из 6 элементов) ";
                const int size = 6;
                int ms[size];
                for (int i = 0; i < 7; i++) // Заполнение массива с превышением элементов
                {
                    if (i > 5) throw MemErr();
                    ms[i] = i;
                    cout << ms[i] << " ";
                }
            }

            else if (ch == '3')
            {
                cout << "\n Проверка открытия файла (по заданному пути) ";
                char path[128]{ "C:\\print.txt" }; // Попытка открыть несуществующий файл
                cout << path;
                fstream fout(path, ios::in | ios::binary | ios::app);
                if (!fout) throw FileOpErr();
            }
            else
            {
                cout << "Такого варианта нет!" << endl;
            }

        }
        catch (Exception& exception)
        {
            cout << exception.GetError();
        }
        system("pause");
       
    }
}