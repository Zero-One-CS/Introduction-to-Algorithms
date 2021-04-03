#include <iostream>
using namespace std;

void Merge(int arr[], int s, int m, int e)
{
    int n1 = m - s + 1;
    int n2 = e - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[s + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = s;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int m = (e + s) / 2;
    MergeSort(arr, s, m);
    MergeSort(arr, m + 1, e);
    Merge(arr, s, m, e);
}

void printArray(int A[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << A[i] << " ";
}

int main()
{
    int testArr[] = {2, 5, 1, 3, 7, 10, -2};
    int arr_size = sizeof(testArr) / sizeof(testArr[0]);

    cout << "Array Before Sorting \n";
    printArray(testArr, arr_size);

    MergeSort(testArr, 0, arr_size - 1);

    cout << "\nArray After Sorting \n";
    printArray(testArr, arr_size);
    return 0;
}
