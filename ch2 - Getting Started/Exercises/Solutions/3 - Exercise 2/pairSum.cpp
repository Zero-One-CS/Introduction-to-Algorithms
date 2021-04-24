#include<iostream>
#include<vector>

using namespace std;

void Merge(int arr[], int s, int m, int e)
{
    int n1 = m - s + 1 ;
    int n2 = e - m ;

    int Right[n2], Left[n1];

    for (int i =0; i<n1; i++){
        Left[i] = arr[s+i];
    }

    
    for (int j =0; j<n2; j++){
        Right[j] = arr[m + j+ 1];
    }

    int i = 0;
    int j =0 ;
    int k = s;

    while (i< n1 && j <n2) 
    {
        if(Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1 )
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2 )
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
    
    
}

void MergeSort(int arr[], int start, int end)
{
    if (start >= end ) {
        return;
    }
    int m = (end+start)/2;
    MergeSort(arr, start, m);
    MergeSort(arr,m+1, end);
    Merge(arr, start, m , end);
}

int binarySearch(int arr[], int size, int key, int leftIdx = 0)
{
   int midPoint, rightIdx = size - 1;
   while(leftIdx <= rightIdx)
    {
       midPoint = (leftIdx + rightIdx) / 2;
       if(arr[midPoint] > key)
       {
           rightIdx = midPoint - 1;
       }
       else if(arr[midPoint] < key)
       {
           leftIdx = midPoint + 1;
       }
       else
        return midPoint;
   }
   return -1;
}

vector<int> solution(int sortedArray[], int size, int target)
{
    int rem, res;
    vector<int> sol;
    for(int i=0; i<size; i++)
    {
        rem = target - sortedArray[i];
        res = binarySearch(sortedArray,size,rem, i + 1);
        if(res != -1)
        {
            sol.push_back(sortedArray[i]);
            sol.push_back(rem);
            return sol;
        }
    }
    return sol;

}

int main()
{
    vector<int> sol;
    int testArray[] = {5,1,3,18,16,20,55,1,-5};
    int arrSize = sizeof(testArray) / sizeof(testArray[0]);

    int numSearchFor = 10;
    // sort array 
    MergeSort(testArray,0,arrSize-1);
    sol =  solution(testArray,arrSize,numSearchFor);
    if(sol.size() != 0)
    {
        cout<<"the two pairs which there sum = "<<numSearchFor<<" are "<<sol[0]<<","<<sol[1]<<endl;
    }
    else
    {
        cout<<"Not founded!\n";
    }
    return 0;
}