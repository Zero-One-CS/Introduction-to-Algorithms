#include<iostream>

using namespace std;

int binarySearch(int arr[], int size, int key)
{
   int midPoint, leftIdx = 0, rightIdx = size - 1;
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

int main()
{

    int testArr[] = {1,2,3,4,10,15,20,100};
    int key = 1;
    int sol = binarySearch(testArr, 8, key);
    if(sol != -1)
    {
        cout<<"Found: "<<key<<" at index = "<<sol<<endl;
    }
    else
        cout<<key<<" not exist in the Given Array\n";
    return 0;
}