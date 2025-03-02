#include<bits/stdc++.h>
using namespace std;

bool bin_sear(int ar[],int low,int high, int data)
{



    while(low<=high)
    {
        int mid = (low+high)/2;

        if(ar[mid] == data)
        {
            return true;
        }
        else if(ar[mid] > data)
        {
            low = mid +1;
        }
        else if(ar[mid] < data)
        {
            high = mid -1;
        }
    }

    return false;
}

int main()
{
    int ar[10] = {2,4,6,8,9,11,23,45,55,66};
    int low = 0;
    int high = 9;

    int data;
    cout << " enter data" << endl;
    cin >> data;
    bool status = bin_sear(ar,low,high,data);


    if(status == true)
    {
        cout << "item available" << endl;
    }
    else if(status == false)
    {
        cout << "not here " << endl;
    }

    return 0;
}
