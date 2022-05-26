#include <iostream>
#include <vector>
#include <list>
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

    int pathsOfLength(int u, int v, int r)
    {
        if (u >= n || v >= n)
            return 0;

        int res[n][n];
        int temp[n][n];

        // res = arr
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                res[i][j] = arr[i][j];
        }

        int s;
        for (int i = 0; i < r - 1; i++)
        {
            // temp = res * arr
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    s = 0;
                    for (int l = 0; l < n; l++)
                        s += (res[j][l] * arr[l][k]);
                    temp[j][k] = s;
                }
            }

            // res = temp
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    res[i][j] = temp[i][j];
            }
        }
        return res[u][v];
    }
};

int main()
{
    Graph G(5);
    cout << "Enter the graph" << endl;
    G.inputGraph();
    int u, v, r;
    cout << "Enter initial , final nodes and path length" << endl;
    cin >> u >> v >> r;
    cout << "Required No. of paths: " << G.pathsOfLength(u, v, r) << endl;
    return 0;
}

/*
0 1 1 1 0
1 0 0 1 1
1 0 0 0 1
1 1 0 0 1
0 1 1 1 0

output = 3 for u = 0 , v = 4 , r = 2
*/