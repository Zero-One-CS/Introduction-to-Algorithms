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

void HeapSort(int arr[], int length)
{
    BuildMaxHeap(arr, length);

    for (int i = length - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        // length -= 1 ;
        // MaxHeapify(arr, length, 0);
        MaxHeapify(arr, i, 0);
    }
}
