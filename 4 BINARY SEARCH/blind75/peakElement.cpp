#include <bits/stdc++.h>
using namespace std;
// Peak Element : the element which is strictly grerater than its neighbours are peak element , find the peak element in the mountain array and return its index

int peakElement_Brute(vector<int> arr, int n)
{
    // brute force approach , linear search and condition for mountain array
    // time :O(n) ,space :O(1)

    int maxAns = -1;
    // peak element is nothing but maximum value of array 
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i] > arr[i - 1]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            if (i > maxAns)
                maxAns = i;
        }
    }
    return maxAns;
}

int peakElement_Optimised(vector<int> arr, int n)
{
    // optimised Approach : concept - binary search
    // time :O(log n  ),space : O(1)
    int start = 0, end = n - 1;
    while (start < end)
    { // important condtion start and end will not become equal
        int mid = (start + (end - start) / 2);
        if (arr[mid] < arr[mid + 1])
        { // increasing slope area

            start = mid + 1;
        }
        else
        {
            // arr[mid+1]>arr[mid], means you are at decreasing slope area
            end = mid;
        }
    }
    return start;
}
int main()
{
    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};
    int n = arr.size();
    cout << peakElement_Brute(arr, n)<<endl;
    cout << peakElement_Optimised(arr, n)<<endl;

    return 0;
}

/*

must try
https://www.interviewbit.com/problems/find-a-peak-element/
https://www.interviewbit.com/problems/perfect-peak-of-array/


*/