#include<bits/stdc++.h>
#include<iostream>

using namespace std;


void inserSort(int a[], int n)
{
    int temp, j;
    for(int i=1; i<n; i++)
    {
        temp=a[i];
        j=i-1;

        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=temp;
    }

}
int main()
{
    int n;

    cout<<"Input array size: ";
    cin>>n;

    int a[n];
    cout << "Input your array: " << endl;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    inserSort(a, n);

    cout << "Sorted array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
Write to Adiba Oishi


