#include <bits/stdc++.h>
using namespace std;
// Question Name :Traping Rain water harvesting : given an array of heights , we need to find the total amount of water is trapped between the buildings

// Problem Link :https://www.hackerrank.com/challenges/trapping-rain-water/problem

// function to find the right max height of the building
int findRightMaxHeight(vector<int> arr, int n, int index)
{
    int rightMax = arr[index];
    for (int i = index; i < n; i++)
    {
        rightMax = max(rightMax, arr[i]);
    }
    return rightMax;
}
int trapingRainWater_Brute(vector<int> arr, int n)
{

    // concept : prefixMax, suffixMax , formula = (leftMaxHeight- rightMaxHeight) - currHeight
    // time : O(n^2) , space : O(1);
    int sum = 0;
    int leftMax = arr[0];
    for (int i = 0; i < n; i++)
    {
        int currHeight = arr[i];
        leftMax = max(currHeight, leftMax);
        // cout << leftMax << ",";

        int rightMax = findRightMaxHeight(arr, n, i);
        // cout << rightMax << " ";

        int waterTrapped = min(leftMax, rightMax) - currHeight;
        sum += waterTrapped;
    }
    return sum;
}

int trapRainWaterBetter(vector<int> arr, int n)
{
    // concept : Prefix Max, suffixMax ,
    // time ; O(n), space : O(n)
    vector<int> prefixMax(n), suffixMax(n);
    prefixMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], arr[i]);
    }
    suffixMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int waterTrapped = (min(prefixMax[i], suffixMax[i]) - arr[i]);
        sum += waterTrapped;
    }
    return sum;
}

int trapingRainWaterOptimised(vector<int> arr, int n)
{
    // concept : two pointer approach
    // time : O(n) , space : O(1)
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int sum = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {

            if (arr[left] >= leftMax)
            {
                // finding leftMaximum value
                leftMax = arr[left];
            }
            else
            {

                // scope for water storage
                sum += (leftMax - arr[left]);
            }
            left++;
        }
        else
        {
            if (arr[right] >= rightMax)
            {
                rightMax = arr[right];
            }
            else
            {
                // scope for water storage
                sum += rightMax - arr[right];
            }
            right--;
        }
    }
    return sum;
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
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printArray(arr);
    cout << trapingRainWater_Brute(arr, arr.size()) << endl;
    cout << trapRainWaterBetter(arr, arr.size())<<endl;
    cout << trapingRainWaterOptimised(arr, arr.size());

    return 0;
}
/*
article Link :https://takeuforward.org/data-structure/trapping-rainwater/

link :https://leetcode.com/problems/trapping-rain-water/description/    (done)


Must try problems :

*/