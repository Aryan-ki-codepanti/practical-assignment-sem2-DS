#include <iostream>
using namespace std;

class Graph
{
    int n;
    int **arr;

public:
    Graph(int a)
    {
        n = a;
        arr = new int *[n];
        for (int i = 0; i < n; i++)
            arr[i] = new int[n];
    }

    void inputGraph()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
    }

    bool isComplete()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j && arr[i][j])
                    return false;
                else if (i != j && (!arr[i][j] || !arr[j][i]))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    int size = 3;
    Graph G(size);
    cout << "Enter the graph matrix" << endl;
    G.inputGraph();
    if (G.isComplete())
        cout << "Graph is complete" << endl;
    else
        cout << "Graph is complete" << endl;
    return 0;
}