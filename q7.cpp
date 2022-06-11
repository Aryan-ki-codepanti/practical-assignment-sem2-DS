#include <iostream>

using namespace std;

class Array
{

    int n;
    int *arr;

public:
    Array(int a)
    {
        n = a;
        arr = new int[a];
    }

    void takeInput()
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void displayArr()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int binarySearch(int left, int right, int key)
    {
        if (left > right)
            return -1;
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            return binarySearch(mid + 1, right, key);

        else
            return binarySearch(left, mid - 1, key);
    }
};

int main()
{
    int n, key, pos;
    cout << "Enter size of array : ";
    cin >> n;

    // declaring array object
    Array A(n);
    cout << "Enter elements of array" << endl;
    A.takeInput();
    cout << "Enter element to be searched : ";
    cin >> key;

    pos = A.binarySearch(0, n - 1, key);

    if (pos == -1)
        cout << key << " not found" << endl;
    else
        cout << key << " found at index " << pos << endl;
    return 0;
}