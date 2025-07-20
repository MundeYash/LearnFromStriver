#include <bits/stdc++.h>
using namespace std;
// Pivot Element : given an sorted array which is rotated at some index and we need to find the index of minimum element where this is rotated

// Note : Pivot element is nothing but the index of smallest element in the array

int pivotElement_Brute(vector<int> arr, int n)
{
    // Brute force : concept - linear  search ,
    // time : O(n), space : O(1);
    int ans = -1;
    int minValue = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        if (value < minValue)
        {
            minValue = value;
            ans = i;
        }
    }
    return ans;
}

int pivotElement_Optimised(vector<int> arr, int n)
{
    // optimised appraoch :
    // concept - binary search, time : O(log n ), space : O(1)
    int start = 0, end = n - 1;
    while (start < end)
    {
        int mid = (start + (end - start) / 2);
        if (arr[mid] > arr[0])
        {
            // first portion increasing
            start = mid + 1;
        }
        else
        {
            // second portion , increasing but less than arr[0]
            end = mid;
        }
    }
    return start;
}
int main()
{
    vector<int> arr = {11, 13, 15, 17};
    int n = arr.size();
    cout << "Index : " << pivotElement_Brute(arr, n) << endl;
    cout << "Index : " << pivotElement_Optimised(arr, n) << endl;

    return 0;
}

/*
article :

link :

must try
 https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/    (done)
 https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/       (done)


 https://www.interviewbit.com/problems/rotated-array/
 https://www.interviewbit.com/problems/rotated-sorted-array-search/
 


*/