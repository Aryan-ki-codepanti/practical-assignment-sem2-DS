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
        for (int d = degree; d > 0; d--)
            cout << coefficients[d] << "x^" << d << " + ";
        cout << coefficients[0] << "x^0" << endl;
    }
    int f(int n)
    {
        int res = 0;
        for (int d = degree; d >= 0; d--)
            res += coefficients[d] * pow(n, d);
        return res;
    }
};

int main()
{
    int n,m;
    cout << "Enter degree of polynomial : ";
    cin >> n;
    Polynomial p(n);
    cout << "Enter coefficients of polynomial" << endl;
    p.inputCoefficients();
    cout << "Polynomial : ";
    p.display();
    cout << "Enter a number : ";
    cin >> m;
    cout << "Value at " << m << " : " << p.f(m);
    return 0;
}