#include <iostream>
using namespace std;

// l = (m − 1)i + 1

class M_AryTree
{
    int i, l, m;

public:
    M_AryTree(int i, int m)
    {
        this->i = i;
        this->m = m;
        l = (m - 1) * i + 1;
    }

    int getLeaves()
    {
        return l;
    }
};

int main()
{
    int i, m;
    cout << "Enter m (of m-ary tree) and number of internal nodes " << endl;
    cin >> m >> i;

    M_AryTree tree(i, m);

    cout << "Number of leaves : " << tree.getLeaves();
    return 0;
}