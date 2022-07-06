#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

class Array
{
    int n, a, b;
    int *arr;

public:
    Array()
    {
        n = 0;
        a = 0;
        b = 0;
    }

    Array(int n, int a, int b)
    {
        this->n = n;
        this->a = a;
        this->b = b;
        arr = new int[n];
    }

    ~Array()
    {
        delete[] arr;
    }

    void setArray()
    {
        for (int i = 0; i < n; i++)
            arr[i] = randomNumber();
    }

    int randomNumber()
    {
        int r = (rand() % (b - a)) + a;
        return r;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int bubbleSort()
    {
        int comparisons = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    comparisons++;
                }
            }
        }
        return comparisons;
    }
};

int main()
{

    ofstream out("q8.csv");
    srand((unsigned)time(NULL));
    int n, a, b;
    n = 10;
    a = 1;
    b = 20;
    Array arr;

    int comparisons;
    for (int i = 1; i <= 250; i += 5)
    {
        arr = Array(i, a, b);
        arr.setArray();
        // cout << "Original : ";
        // arr.display();

        comparisons = arr.bubbleSort();
        // cout << "Sorted : ";
        // arr.display();
        cout << "n : " << i << " Comparisons : " << comparisons << endl;
        out << i << "," << comparisons << endl;
    }
    out.close();

    return 0;
}