#include<iostream>

using namespace std;

void insertionSort(int arr[], int arrSize)
{
    /*
        Applay insertion sort on arr (inplace)
    */
    if(arrSize <= 1)
        return;

    int temp, itr, key, idx = 1;

    while(idx < arrSize)
    {
        key = arr[idx];
        itr = idx - 1;
        while(itr >= 0 && arr[itr] > key)
        {
            // swap between itr , itr + 1
            temp = arr[itr];
            arr[itr] = key;
            arr[itr + 1] = temp;

            itr--;
        }
        idx++;
    }
}


void printArray(int arr[], int arrSize)
{
    for(int i=0; i < arrSize; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    int testArray[] = {2, 5, 1 ,3, 7 ,10 ,-2};
    int arrSize = sizeof(testArray) / sizeof(testArray[0]);

    cout<<"Array before sorting\n";
    printArray(testArray, arrSize);

    insertionSort(testArray, arrSize);

    cout<<"Array after sorting\n";
    printArray(testArray, arrSize);

    return 0;
}