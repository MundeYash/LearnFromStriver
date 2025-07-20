#include <bits/stdc++.h>
using namespace std;
// Question Name : given an array of integers and we need to count the number of inversions in the array. An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].
int countInversion_Brute(vector<int> arr, int n)
{
    // concept : brute force 2 loops , time : O(n^2) , space : O(1)
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int merge(vector<int> &arr, int low, int mid, int high)
{

    int count = 0;
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            // this is not valid inversion pair
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            // this is valid inversion pair
            count += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if some of the element are left in the left array
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // if some of the element are left in the right array

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // copy the element to the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count;
}
int mergeSortCount(vector<int> &arr, int low, int high)
{

    // divide and conquer approach : concept : merge sort , time : O(n log n) , space : O(n)
    // divide   the array and merge
    int count = 0;
    // base case
    if (low >= high)
    {
        // no two values to compare

        return 0;
    }

    int mid = (low + high) / 2;
    count += mergeSortCount(arr, low, mid);
    count += mergeSortCount(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

int countInversion_Optimised(vector<int> &arr, int n)
{
    // concept : merge sort , time : O(n log n) , space : O(n)
    int count = mergeSortCount(arr, 0, n - 1);
    return count;
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
    cout << countInversion_Brute(arr, arr.size()) << endl;

    cout << "Optimised Approach ";
    cout << countInversion_Optimised(arr, arr.size()) << endl;

    return 0;
}
/*
article Link :

*/