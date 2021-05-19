#include <iostream>
#include <locale.h>

using namespace std;

template <class Data> class Stack
{
private:

    Data* array;
    int top;
    int size;

public:

    Stack()
    {
        array = NULL;
        top = -1;
        size = 0;
    }

    Stack(int n)
    {
        size = n;
        top = -1;
        array = new Data[size];
    }

    ~Stack()
    {
        delete[] array;
    }

    bool Full()
    {
        return top == (size - 1);
    }

    bool Empty()
    {
        return top == -1;
    }

    Data Top()
    {
        if(!Empty())
            return array[top];
    }

    Data Pop()
    {
        if(!Empty())
            return array[top--];
    }

    bool Push(Data in)
    {
        if (Full())
            return false;
            
        array[++top] = in;
        return true;
    }

};

template <class T>
void interface(T & stack)
{
    char choice;
    int in;

    do
    {
        system("cls");

        cout << "[P]op | P[u]sh | [T]op | [Н]азад" << endl;

        cin >> choice;
        getchar();

        switch (choice)
        {
        case 'P': case 'p':

            if (stack.Empty())
                cout << "Стек пуст." << endl;
            else
                cout << stack.Pop() << endl;

            break;

        case 'U': case 'u':

            cout << "Введите значение: ";
            cin >> in;
            getchar();

            if (!stack.Push(in))
            {
                cout << "Стек заполнен." << endl;
            }

            break;

        case 'T': case 't':

            if (stack.Empty())
                cout << "Стек пуст." << endl;
            else
                cout << stack.Top() << endl;

            break;
        }

        cout << "Нажмите для подтверждения..." << endl;
        getchar();

    } while (choice != 'Н');


}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    char choice;
    Stack <double> dstack(5);
    Stack <char> cstack(5);

    do
    {
        system("cls");

        cout << "Стек [D]ouble | Стек [C]har | [В]ыход" << endl;

        cin >> choice;
        getchar();

        switch (choice)
        {
        case 'D': case 'd':

            interface(dstack);
            break;

        case 'C': case 'c':

            interface(cstack);
            break;
        }
    } while (choice != 'В');

}