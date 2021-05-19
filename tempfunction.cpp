#include <iostream>
#include <locale.h>

using namespace std;

template <typename T>
void print(T* massive, int size)
{
    int i;

    for (i = 0; i < size; i++)
        cout << massive[i] << " ";

    cout << endl;
}

template <typename T> 
void msort(T* massive, int size)
{
    int i, beg = 0, end = size - 1, m = 0, n = 0;
    T omin, pmin;

    while ((end - beg) > 0)
    {
        omin = pmin = 0;

        for (i = beg; i <= end; i++)
        {
            if (massive[i] <= omin)
            {
                omin = massive[i];
                m = i;
            }

            if (massive[i] >= 0 && (massive[i] <= pmin || pmin == 0))
            {
                pmin = massive[i];
                n = i;
            }
        }

        if ((end - beg) != 1)
        {
            massive[m] = massive[beg];
            massive[beg] = omin;

            massive[n] = massive[end];
            massive[end] = pmin;
        }
        
        else // если размер чётный
        {
            if (massive[beg] > massive[end])
            {
                pmin = massive[end];
                massive[end] = massive[beg];
                massive[beg] = pmin;
            }
        }
        
        beg++;
        end--;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double a[5] = { 243.321, -452, 34, 0, -2 };
    char b[6] = { 54, 57, 54, -43, -60, -71};

    cout << "Исходные массивы:" << endl;
    print(a, 5);
    print(b, 6);

    cout << "Идёт обработка..." << endl;
    msort(a, 5);
    msort(b, 6);

    cout << "Нажмите для подтверждения...";
    getchar();

    cout << "Обработанные массивы:" << endl;
    print(a, 5);
    print(b, 6);

    cout << "Нажмите для подтверждения...";
    getchar();

    return 0;
}


