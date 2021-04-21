#include<iostream>

using namespace std;

void selectionSort(int arr[], int arrSize)
{
    int currMinVal, currMinIdx;
    for(int i = 0; i<arrSize; i++)
    {
        currMinVal = arr[i];
        currMinIdx = i;
        for(int j= i + 1; j<arrSize; j++)
        {
            if(arr[j] < currMinVal)
            {
                currMinVal = arr[j];
                currMinIdx = j;
            }
        }
        arr[currMinIdx] = arr[i];
        arr[i] = currMinVal;

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

    selectionSort(testArray, arrSize);

    cout<<"Array after sorting\n";
    printArray(testArray, arrSize);

    return 0;
}