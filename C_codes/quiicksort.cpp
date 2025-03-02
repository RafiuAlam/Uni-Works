#include <bits/stdc++.h>
using namespace std;

int counter(int arr[], int f, int l)
{

    int x = arr[f];
    int count = 0;

    for (int i = f + 1; i <= l; i++)
    {
        if (arr[i] <= x)
        {
             count++;
        }
    }

    int xIndex = f + count;

    swap(arr[xIndex], arr[f]);

    int i = f;
    int j = l;

    while (i < xIndex && j > xIndex)
    {

        while (arr[i] <= x)
        {
            i++;
        }

        while (arr[j] > x)
        {
            j--;
        }

        if (i < xIndex && j > xIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return xIndex;
}

void quickSort(int arr[], int f, int l)
{

    if (f >= l)
    {
         return;
    }

    int n = counter(arr, f, l);

    quickSort(arr, f, n - 1);
    quickSort(arr, n + 1, l);
}

int main()
{
    int a[5];
    cout << "Enter an array of 5 elements: " << endl;
    for(int i=0; i<5; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, 5 - 1);

    cout << "Your array shorted in ascending order: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

