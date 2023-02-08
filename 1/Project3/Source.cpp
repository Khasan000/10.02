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
    ~List(); //Деструктор
    void Show(); 
    void Add(int x); 
};

List::~List() //Деструктор
{
    
    
        while (Head) //Пока по адресу на начало списка что-то есть
        {
            try
            {
                Tail = Head->Next; //Резервная копия адреса следующего звена списка
                delete Head; //Очистка памяти от первого звена
                Head = Tail; //Смена адреса начала на адрес следующего элемента
            }
            catch(...) {
                cout << "Something went wrong..." << endl;
            }
           
        }
        
    
    
}

void List::Add(int x)
{
    Node* temp = new Node; //Выделение памяти под новый элемент структуры
    temp->Next = nullptr;  //Указываем, что изначально по следующему адресу пусто
    temp->x = x;//Записываем значение в структуру

    if (Head != nullptr) //Если список не пуст
    {
        temp->Prev = Tail; //Указываем адрес на предыдущий элемент в соотв. поле
        Tail->Next = temp; //Указываем адрес следующего за хвостом элемента
        Tail = temp; //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->Prev = nullptr; //Предыдущий элемент указывает в пустоту
        Head = Tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void List::Show()
{
    //ВЫВОДИМ СПИСОК С КОНЦА
    Node* temp = Tail;
    //Временный указатель на адрес последнего элемента
    while (temp != nullptr) //Пока не встретится пустое значение
    {
        cout << temp->x << " "; //Выводить значение на экран
        try
        {
            temp = temp->Prev; //Указываем, что нужен адрес предыдущего элемента

        }
        catch (...)
        {
            cout << "something is wrong with the pointer(prev)" << endl;
        }
    }
    cout << "\n";

    //ВЫВОДИМ СПИСОК С НАЧАЛА
    temp = Head; //Временно указываем на адрес первого элемента
    while (temp != nullptr) //Пока не встретим пустое значение
    {
        cout << temp->x << " "; //Выводим каждое считанное значение на экран
        try
        {
            temp = temp->Next; //Указываем, что нужен адрес предыдущего элемента

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
    List lst; //Объявляем переменную, тип которой есть список
    lst.Add(100); //Добавляем в список элементы
    lst.Add(200);
    lst.Add(900);
    lst.Add(888);

    lst.Show(); //отображаем список на экране
    system("PAUSE");
}