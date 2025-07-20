#include <bits/stdc++.h>
using namespace std;
// Search sorted rotated : given an array which was sorted initially , now rotated at some index pivot , we need to find the target value and return its index if it exists in the array , other wise return -1

int sortedRotatedSearch_Brute(vector<int> arr, int target)
{
    // Brute force : concept : linear search , time :O(n ), space : O(1)

    int n = arr.size();
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

// helper function to find pivot index
int findPivot(vector<int> arr)
{

    int n = arr.size();
    int start = 0, end = n - 1;
    while (start < end)
    {
        int mid = (start + (end - start) / 2);
        if (arr[mid] >= arr[0])
        {
            // pivot element is in right side and you are on upper increasing slope
            start = mid + 1;
        }
        else
        {
            // pivot element is in left side and you are on lower increasing slope
            end = mid;
        }
    }
    return start;
}
// helper function binary search
int binarySearch(vector<int> arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int sortedRotatedSearch_Optimised(vector<int> arr, int target)
{
    // optimised approach : concept : binary search and pivot element
    // time : O(log n ), space : O(1)

    int n = arr.size();
    if (n == 1)
    {
        if (arr[0] == target)
            return 0;
        else
            return -1;
    }

    int pivot = findPivot(arr);

    // search space finding and apply binary search

    if (target >= arr[0] && target <= arr[pivot - 1])
    {

        return binarySearch(arr, 0, pivot - 1, target);
    }

    else if (target >= arr[pivot] && target <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, target);
    }
    else
    {
        // means value does not exist
        return -1;
    }
}
int main()
{
    vector<int> arr = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
    int target = 4;
    cout << "The target element is at index : " << sortedRotatedSearch_Brute(arr, target) << endl;
    cout << "The target element is at index : " << sortedRotatedSearch_Optimised(arr, target) << endl;

    return 0;
}

/*
article :https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/
link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

must try

*/