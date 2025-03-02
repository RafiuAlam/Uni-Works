#include<bits/stdc++.h>
#include<vector>
using namespace std;

void selectionSort(vector<int> &v)
{
    for (int i = 0; i < (v.size() - 1); i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < v.size(); j++)
        {

            if (v[j] < v[min_idx])
            {
                min_idx = j;
            }

        }
        swap(v[min_idx],v[i]);
    }
}

void printVector(vector<int> &v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout << v[i] <<" ";
    }
}

int main()
{
    cout << "Enter vector elements: " << endl;
    vector<int> vec1;
    for(int i=0; i<5; i++)
    {
        int x;
        cin >> x;
        vec1.push_back(x);
    }

    cout << "After sorting: " << endl;

    selectionSort(vec1);
    printVector(vec1);

    return 0;
}
