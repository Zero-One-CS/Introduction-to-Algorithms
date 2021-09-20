#include <iostream>
using namespace std;

void PrintHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void MaxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1; // Cause In Heap you start index at 1 but in array you start index at 0
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(int arr[], int n)
{
    int startPoint = (n / 2) - 1;
    for (int i = startPoint; i >= 0; i--)
    {
        MaxHeapify(arr, n, i);
    }
}

int main()
{

    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    MaxHeapify(arr, n, 2);
    PrintHeap(arr, n);

    // BuildMaxHeap(arr, n);
}