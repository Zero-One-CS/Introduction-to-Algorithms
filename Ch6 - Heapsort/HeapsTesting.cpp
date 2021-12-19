#include <iostream>
#include "Heaps.h"

using namespace std;

int main()
{

    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    // MaxHeapify(arr, n, 2);
    HeapSort(arr, n);
    PrintHeap(arr, n);

    // BuildMaxHeap(arr, n);
}