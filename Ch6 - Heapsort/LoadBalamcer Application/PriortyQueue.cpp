#ifndef QUEUE_H
#include "PriortyQueue.h"
#endif

#include <iostream>
#include "../Heaps.h"
using namespace std;

template <class T>
void PriortyQueue<T>::resize(int newSize)
{
    T *temp = new T[newSize];
    for (int i = 0; i < size; i++)
    {
        temp[i] = elements[i];
    }
    delete[] elements;
    elements = temp;
    size = newSize;
}

template <class T>
void PriortyQueue<T>::MaxHeapify(T arr[], int i)
{
    int largest = i;
    int left = 2 * i + 1; // Cause In Heap you start index at 1 but in array you start index at 0
    int right = 2 * i + 2;

    if (left < size && arr[left].processTime < arr[largest].processTime)
    {
        largest = left;
    }

    if (right < size && arr[right].processTime < arr[largest].processTime)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest);
    }
}

template <class T>
void PriortyQueue<T>::BuildMaxHeap(T arr[])
{
    int startPoint = (size / 2) - 1;
    for (int i = startPoint; i >= 0; i--)
    {
        MaxHeapify(arr, i);
    }
}

template <class T>
void PriortyQueue<T>::enqueue(T element)
{
    resize(size + 1);
    cout << "Size Before Enqueue: " << size << endl;
    elements[size] = element;
    BuildMaxHeap(elements);
}

template <class T>
T PriortyQueue<T>::dequeue()
{
    swap(elements[size], elements[0]);
    T element = elements[size];
    resize(size - 1);
    BuildMaxHeap(elements);

    return element;
}

template <class T>
T PriortyQueue<T>::peek()
{
    return elements[0];
}

template <class T>
bool PriortyQueue<T>::isEmpty()
{
    if (size == 0)
    {
        return false;
    }

    return true;
}