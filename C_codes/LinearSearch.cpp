#include<bits/stdc++.h>
using namespace std;

int main()
{
    //int ar[5] = {5,8,9,12,15};
    int n;
    int ar[n];

    cout << "Enter the length of array" << endl;
    cin >> n;
    cout << " enter the elements of array" << endl;
    int data;
    for(int i=0; i<=n; i++)
    {
        cin >> data;
        ar[i] = data;
    }

    int s_data;
    cout << "Enter data" << endl;
    cin >> s_data;

    int flag = 0;

    for(int i=0; i<=n; i++)
    {
        if(ar[i]== s_data)
        {
            flag = 1;
            break;
        }

    }
    if(flag == 1)
    {
        cout << "Data Found" << endl;
    }
    else
    {
        cout << "Data not found" << endl;
    }

    return 0;
}

/*int lin_search()
{
    int flag = 0;
}*/
