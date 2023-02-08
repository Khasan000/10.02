#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Exception // ������������ ����� ������ (������� �� ����� ��������� �� ������)
{
public:
    string E_error; // ������������ ���������� � ������� �� ������
    Exception() : E_error("\n ���������� ������: ") {};
    virtual const string GetError() = 0;
};


class DevZero : public Exception // (�������������� ������ - ������� �� 0)
{
public:
    string Z_error; // ���������� �� ������������������ ������� ������
    DevZero() : Z_error("������� �� ���� !!!") { }
    virtual const string GetError() override
    {
        return E_error + Z_error;
    }
};

class MemErr : public Exception // (�������������� ������ - ������������ �������)
{
public:
    string M_error; // ���������� �� ������������������ ������� ������
    MemErr() : M_error("������������ ������ !!!") { }
    virtual const string GetError() override
    {
        return E_error + M_error;
    }
};

class FileOpErr : public Exception // (�������������� ������ - ������������ �������)
{
public:
    string F_error; // ���������� �� ������������������ ������� ������
    FileOpErr() : F_error("�� ������� ������� ���� !!!") { }
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
        cout << "\n 0 - �����";
        cout << "\n 1 - �������� ������� ������� a �� b (5 �� 0)";
        cout << "\n 2 - �������� �������� ����� (�� ��������� ����) ";
        cout << "\n 3 - �������� �������� ����� (�� ��������� ����) ";
        cout << "\n     �������� �������� ���������� ��� ��������� ������: ";
        cin >> ch;
        cout << endl << endl;

        try
        {
            if (ch == '1')
            {
                a = 5; // �������������� � ������� �� 0
                b = 0;

                if (b == 0) throw DevZero();
                int c = a / b;
            }

            else if (ch == '2')
            {
                cout << "\n �������� ���������� ������ (7 ������� �� ������ � ������ �� 6 ���������) ";
                const int size = 6;
                int ms[size];
                for (int i = 0; i < 7; i++) // ���������� ������� � ����������� ���������
                {
                    if (i > 5) throw MemErr();
                    ms[i] = i;
                    cout << ms[i] << " ";
                }
            }

            else if (ch == '3')
            {
                cout << "\n �������� �������� ����� (�� ��������� ����) ";
                char path[128]{ "C:\\print.txt" }; // ������� ������� �������������� ����
                cout << path;
                fstream fout(path, ios::in | ios::binary | ios::app);
                if (!fout) throw FileOpErr();
            }
            else
            {
                cout << "������ �������� ���!" << endl;
            }

        }
        catch (Exception& exception)
        {
            cout << exception.GetError();
        }
        system("pause");
       
    }
}