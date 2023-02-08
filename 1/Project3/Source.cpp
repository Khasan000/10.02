#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node      
{
    int x;     
    Node* Next, * Prev; 
};

class List   
{
    Node* Head, * Tail; 
public:
    List() :Head(nullptr), Tail(nullptr) {};
    ~List(); //����������
    void Show(); 
    void Add(int x); 
};

List::~List() //����������
{
    
    
        while (Head) //���� �� ������ �� ������ ������ ���-�� ����
        {
            try
            {
                Tail = Head->Next; //��������� ����� ������ ���������� ����� ������
                delete Head; //������� ������ �� ������� �����
                Head = Tail; //����� ������ ������ �� ����� ���������� ��������
            }
            catch(...) {
                cout << "Something went wrong..." << endl;
            }
           
        }
        
    
    
}

void List::Add(int x)
{
    Node* temp = new Node; //��������� ������ ��� ����� ������� ���������
    temp->Next = nullptr;  //���������, ��� ���������� �� ���������� ������ �����
    temp->x = x;//���������� �������� � ���������

    if (Head != nullptr) //���� ������ �� ����
    {
        temp->Prev = Tail; //��������� ����� �� ���������� ������� � �����. ����
        Tail->Next = temp; //��������� ����� ���������� �� ������� ��������
        Tail = temp; //������ ����� ������
    }
    else //���� ������ ������
    {
        temp->Prev = nullptr; //���������� ������� ��������� � �������
        Head = Tail = temp; //������=�����=��� �������, ��� ������ ��������
    }
}

void List::Show()
{
    //������� ������ � �����
    Node* temp = Tail;
    //��������� ��������� �� ����� ���������� ��������
    while (temp != nullptr) //���� �� ���������� ������ ��������
    {
        cout << temp->x << " "; //�������� �������� �� �����
        try
        {
            temp = temp->Prev; //���������, ��� ����� ����� ����������� ��������

        }
        catch (...)
        {
            cout << "something is wrong with the pointer(prev)" << endl;
        }
    }
    cout << "\n";

    //������� ������ � ������
    temp = Head; //�������� ��������� �� ����� ������� ��������
    while (temp != nullptr) //���� �� �������� ������ ��������
    {
        cout << temp->x << " "; //������� ������ ��������� �������� �� �����
        try
        {
            temp = temp->Next; //���������, ��� ����� ����� ����������� ��������

        }
        catch (...)
        {
            cout << "something is wrong with the pointer(next)" << endl;
        }
    }
    cout << "\n";
}

int main()
{
    /*system("CLS");*/
    List lst; //��������� ����������, ��� ������� ���� ������
    lst.Add(100); //��������� � ������ ��������
    lst.Add(200);
    lst.Add(900);
    lst.Add(888);

    lst.Show(); //���������� ������ �� ������
    system("PAUSE");
}