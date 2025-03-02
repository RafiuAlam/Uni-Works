#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int a = 0;
    vector<int> v1;
    cout << "Enter vector element: " << endl;
    for(int i = 0; i<5; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    int num;
    cout << "Enter a number: " << endl;
    cin >> num;


    for(int i=0; i<5; i++)
    {
        if(v1[i]==num)
        {
            cout << "Found" << endl;
            a=1;
        }
    }
    if(a==0)
    {
        cout << "Not found";
    }

    return 0;
}
