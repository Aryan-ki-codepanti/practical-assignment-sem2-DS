#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
    int degree;
    int *coefficients;

public:
    Polynomial(int d)
    {
        degree = d;
        coefficients = new int[d + 1];
    }

    void inputCoefficients()
    {
        for (int d = degree; d >= 0; d--)
            cin >> coefficients[d];
    }

    void display()
    {
        for (int d = degree; d >= 0; d--)
            cout << coefficients[d] << " ";
        cout << endl;
    }
    int f(int n)
    {
        int res = 0;
        for (int d = degree; d >= 0; d--)
            res += (coefficients[d] * (int)(pow(n, d)));

        return res;
    }
};

int main()
{
    int n = 2;
    Polynomial p(n);
    p.inputCoefficients();
    p.display();
    cout << p.f(5);
    return 0;
}