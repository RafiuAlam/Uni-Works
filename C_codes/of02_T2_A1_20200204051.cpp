#include<bits/stdc++.h>
#include<vector>
using namespace std;

void BubbleSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void printVector(vector<int> &v)
{
    for (int i=0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter vector elements: " << endl;
    vector<int> v1;
    for(int i=0; i<5; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    cout << "After sorting the vector: " << endl;

    BubbleSort(v1);
    printVector(v1);

    return 0;
}
