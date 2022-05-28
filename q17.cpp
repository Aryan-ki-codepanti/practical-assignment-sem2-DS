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

    int indegree(int v)
    { // col v sum
        if (v >= n)
            return -1; // invalid vertex
        int res = 0;

        for (int i = 0; i < n; i++)
            res += arr[i][v];

        return res;
    }

    int outdegree(int v)
    { // row v sum
        if (v >= n)
            return -1; // invalid vertex
        int res = 0;

        for (int i = 0; i < n; i++)
            res += arr[v][i];

        return res;
    }
};

int main()
{
    int size = 3;
    Graph G(size);
    cout << "Enter graph matrix" << endl;
    G.inputGraph();

    int vertex = 1;

    cout << "Indegree of vertex " << vertex << " : " << G.indegree(vertex) << endl;
    cout << "Outdegree of vertex " << vertex << " : " << G.outdegree(vertex) << endl;
    return 0;
}