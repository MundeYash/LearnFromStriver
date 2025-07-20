

#include <bits/stdc++.h>

using namespace std;
// Merge sort alogrithm  :  : Given an array of integer and sort the array   .


void merge(vector<int> &arr, int low, int mid, int high)
{
    // time : O(log n ) , space : O(n)
    // two pointers approach
    vector<int> ans;
    int left = low, right = mid + 1;
    while (left <= mid and right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            ans.push_back(arr[right]);
          
            right++;
        }
    }

    // if any of the two array gets exhausted
    while (left <= mid)
    {
        ans.push_back(arr[left]);
        left++;
    }
     while (right <= high)
    {
        ans.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
   
}
void MergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    // recursive case
    int mid = (low + (high - low) / 2);

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
    // Write your code here.
    int low = 0, high = n - 1;
    // base case
    MergeSort(arr, low, high);
}

void print(vector<int> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> a = {3, 1, 3, 4, 2};
    int n = a.size();

    print(a);
    mergeSort(a, n);
    print(a);

    return 0;
}