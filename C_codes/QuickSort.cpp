#include<bits/stdc++.h>
using namespace std;

int part(int ar[],int low,int high)
{
    int pivot = ar[low];
    int i= low,j= high;

    while(i<j)
    {
        while(ar[i] <= pivot)
        {
            i++;
        }
        while(ar[j] >= pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(ar[i],ar[j]);
        }
    }
    swap(ar[low],ar[j]);

    return j;
}
void quickSort(int ar[], int low, int high)
{
    if(low<high)
    {
        int j= part(ar, low, high);

        quickSort(ar,low, j-1);
        quickSort(ar, j+1, high);
    }

}

int main()
{
    int ar[5] = {4,7,9,3,2};
    int low=0, high = 4;

    quickSort(ar, low, high);

    cout << "Sorted list : " << endl;
    for(int i = 0; i<=4; i++)
    {
        cout << ar[i] << endl;
    }
}
