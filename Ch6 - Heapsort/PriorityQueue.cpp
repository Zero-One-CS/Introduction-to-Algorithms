#include <iostream>
#include "Heaps.h"

using namespace std;

void Inqueue(int arr[], int n, int x) //insert_with_priority
{
    arr[n] = x;
    BuildMaxHeap(arr, n + 1);
}

int Dequeue(int arr[], int n) //remove the element from the queue that has the highest priority
{
    swap(arr[n], arr[0]);
    int element = arr[n];
    BuildMaxHeap(arr, n - 1);

    return element;
}

void DeleteElement(int arr[], int index, int n)
{
    swap(arr[n], arr[index]);
    BuildMaxHeap(arr, n - 1);
}

int Peek(int arr[], int n)
{
    return arr[0];
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << length;
    BuildMaxHeap(arr, length);
    cout << "Before Inserting" << endl;
    PrintHeap(arr, length);
    cout << "After Inserting" << endl;
    Inqueue(arr, length, 20);
    PrintHeap(arr, length + 1);
    cout << "Dequeuing" << endl;
    int returnedElement = Dequeue(arr, length);
    PrintHeap(arr, length - 1);
    cout << "Returned Element => Highest Priorty: " << returnedElement << endl;

    int peekedElement = Peek(arr, length);
    cout << "Highest Priorty: " << peekedElement << endl;
}