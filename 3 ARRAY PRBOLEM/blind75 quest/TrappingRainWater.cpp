#include <bits/stdc++.h>
using namespace std;
// Question Name : Traing Rain Water Harvesting problem : Given an array of integers repsenting the heigth of building and we need to find the maximum that will get retained between thme after rain
/*
core concept :  left max and right max and formula : min(leftmax , rightmax) - arr[i] ;

*/
int trappingRainWater_Optimised(vector<int> arr, int n)
{
    // concept : two pointer approach , time : O(n) , space : O(1)
    int ans = 0;
    int left = 0, right = n - 1;
    int leftmax = 0, rightmax = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {

            if (arr[left] >= leftmax)
            {
                leftmax = max(leftmax, arr[left]);
            }
            else
            {
                ans += leftmax - arr[left];
            }
            left++;
        }
        else
        {
            // arr[right]>arr[left ]
            if (arr[right] >= rightmax)
            {
                rightmax = max(rightmax, arr[right]);
            }
            else
            {
                ans += rightmax - arr[right];
            }
            right--;
        }
    }

    return ans;
}
int trappingRainWater_Better(vector<int> arr, int n)
{
    int ans = 0;
    // concept : prefixMaximum and suffixMaximum , time : O(n) , space : O(n)
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = arr[0];
    rightMax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int waterHold = min(leftMax[i], rightMax[i]) - arr[i];
        ans += waterHold;
    }
    return ans;
}
int trappingRainWater_Brute(vector<int> arr, int n)
{
    // concept : find leftMax and rightMaximum , time : O(n^2) , space : O(1)
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int leftMax = 0, rightMax = 0;
        for (int j = i; j >= 0; j--)
        {
            leftMax = max(leftMax, arr[j]);
        }
        for (int j = i; j < n; j++)
        {
            rightMax = max(rightMax, arr[j]);
        }
        int waterHold = min(leftMax, rightMax) - arr[i];
        ans += waterHold;
    }

    return ans;
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
    vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    printArray(arr);

    cout << "Brute force Approach ";
    cout << trappingRainWater_Brute(arr, arr.size()) << endl;

    cout << "Better Approach ";
    cout << trappingRainWater_Better(arr, arr.size()) << endl;

    cout << "Optimised Approach ";
    cout << trappingRainWater_Optimised(arr, arr.size()) << endl;

    return 0;
}
/*
article Link :

*/