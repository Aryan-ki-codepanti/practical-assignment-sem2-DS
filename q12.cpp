#include <iostream>
using namespace std;

class LinearEquation
{
    int n, C;
    int *arr;

public:
    int solutionsCount;
    LinearEquation(int n, int C)
    {
        this->n = n;
        this->C = C;
        arr = new int[n];
        solutionsCount = 0;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void solve(int xIdx)
    {
        if (xIdx == 0)
        {
            arr[xIdx] = C;
            solutionsCount++;
            display();
            return;
        }

        for (int i = 0; i < C; i++)
        {
            arr[xIdx] = i;
            C -= i;
            solve(xIdx - 1);
            C += i;
        }
    }
};

int main()
{
    int n, C;
    cout << "Enter n and C" << endl;
    cin >> n >> C;
    LinearEquation l(n, C);
    l.solve(n - 1);
    cout << "Solutions Count : " << l.solutionsCount << endl;
    return 0;
}