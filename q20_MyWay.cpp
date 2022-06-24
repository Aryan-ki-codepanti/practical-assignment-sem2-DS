#include <iostream>
#include <list>
using namespace std;

class Node
{
public:
    int data;
    list<Node *> children;

    Node(int a)
    {
        data = a;
    }

    void addChild(Node *child)
    {
        children.push_back(child);
    }
};

void bfs(Node *root)
{
    list<Node *> queue = {root};

    Node *poped;
    while (queue.size() > 0)
    {
        poped = *(queue.begin());
        queue.pop_front();
        cout << poped->data << " ";

        for (auto &&child : poped->children)
            queue.push_back(child);
    }
    cout << endl;
}

void dfs(Node *root)
{
    cout << root->data << " ";
    for (auto &&child : root->children)
        dfs(child);
}

int leafNodes(Node *root)
{

    if (!(root->children.size()))
        return 1;

    int leaves = 0;
    for (auto &&child : root->children)
        leaves += leafNodes(child);
    return leaves;
}

int main()
{
    Node *n1, *n2, *n3, *n4, *n5, *n6, *n7;

    n1 = new Node(1);
    n2 = new Node(2);
    n3 = new Node(3);
    n4 = new Node(4);
    n5 = new Node(5);
    n6 = new Node(6);
    n7 = new Node(7);

    n1->addChild(n2);
    n3->addChild(n7);
    n2->addChild(n6);
    n1->addChild(n4);
    n1->addChild(n3);
    n2->addChild(n5);

    Node *root = n1;
    // dfs(root);
    cout << "Leaf Nodes: " << leafNodes(root) << endl;
    bfs(root);

    delete n1, n2, n3, n4, n5, n6, n7;

    return 0;
}