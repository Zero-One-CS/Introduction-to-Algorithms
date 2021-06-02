#include<iostream>
#include<vector>

using namespace std;

vector<int> findMaxCrossingSubArray(vector<int> array, int start, int mid, int end)
{
    int leftSum = INT32_MIN;
    int rightSum = INT32_MIN;

    int leftIdx, rightIdx;
    int sum = 0;
    for(int i=mid+1; i<= end;i++)
    {
        sum += array[i];
        if(sum>rightSum)
        {
            rightIdx = i;
            rightSum = sum;
        }
    }

    sum = 0;
    for(int i = mid; i>= start; i--)
    {
        sum += array[i];
        if(sum>leftSum)
        {
            leftIdx = i;
            leftSum = sum;
        }
    }

    vector<int> res = {leftIdx, rightIdx, leftSum + rightSum};
    return res;
}

vector<int> findMaxSubArray(vector<int> array, int start, int end)
{
    if(start == end)
        return {start, end, array[start]};
    
    int mid = (start + end) / 2;
    vector<int> left =  findMaxSubArray(array, start, mid);
    vector<int> crossing = findMaxCrossingSubArray(array, start, mid, end);
    vector<int> right =  findMaxSubArray(array, mid +1, end);

    if(left[2] > right[2] && left[2] > crossing[2])
        return left;
    
    else if( right[2] > left[2] && right[2] > crossing[2])
        return right;
    
    return crossing;

}

int main()
{

    vector<int> test = {0,13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    vector<int> res = findMaxSubArray(test, 0, test.size()-1);

    cout<<"Max Sub Array sum = "<<res[2]<<" Start Idx = "<<res[0]<<" End idx = "<<res[1]<<endl;
}