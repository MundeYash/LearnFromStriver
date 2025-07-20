#include <bits/stdc++.h>
using namespace std;
// Kadane Algorithm or Maximum sum Subarray : Given an array and we need to find the maximum sum of the subarray (contigious portion of the array )
int maxSum_Optimised(vector<int> arr)
{
    // concept : negative sum , while sum becomes negative will be not use and any value added to it will be reduced , not counted in maxSum

    int n = arr.size();
    int ans = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            // sum becomes negative
            sum = 0;
        }
        ans = max(ans, sum);
    }
    return ans;
}
int maxSum_better(vector<int> arr)
{
    // Better   approach : Explore all the possible subarrays and insted of calculating the sum from scratch, add current value to previous sum
    //,time : O(n^2) , space :O(1)
    int max_sum = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            // subarray creation and sum finding

            // for (int k= i ;k<=j ;k++ ){
            //     sum += arr[k];
            // }
            sum += arr[j];
            // update the max_sum
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

int maxSum_brute(vector<int> arr)
{
    // Brute Force approach : Explore all the possible subarrays ,time : O(n^3) , space :O(1)
    int max_sum = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            // subarray creation and sum finding
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            // update the max_sum
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

// function to print array
void printArray(vector<int> arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    // create array and print its value
    vector<int> arr = {6, -3, -10, 0, 2};
    printArray(arr);

    int ans = maxSum_brute(arr);
    cout << "Maximum sum of the subarray is : " << ans << endl;
    cout << "Maximum sum of the subarray is : " << maxSum_better(arr) << endl;
    cout << "Maximum sum of the subarray is : " << maxSum_Optimised(arr) << endl;

    return 0;
}
/*
article Link :https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/

https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


similiar question 

https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1       (done)
https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1     (rem)

https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1      (DONE)
*/