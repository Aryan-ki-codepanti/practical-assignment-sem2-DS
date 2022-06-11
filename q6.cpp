#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char aux)
{

    if (n == 1)
    {
        cout << "From " << src << " to " << dest << endl;
        return;
    }

    towerOfHanoi(n - 1, src, aux, dest);
    towerOfHanoi(1, src, dest, aux);
    towerOfHanoi(n - 1, aux, dest, src);
}

int main()
{

    int n;
    cout << "Enter number of discs : ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}