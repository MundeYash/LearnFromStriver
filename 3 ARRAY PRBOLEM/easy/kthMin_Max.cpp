#include <bits/stdc++.h>
using namespace std;
// Question Name : Find the Kth minimum and Kth maximum element in the array
pair<int, int> kthMinMaxElement_Brute(vector<int> arr, int k)
{
    int n = arr.size();
    // concept : sorting  , time : O(n log n ) , space : O(1)
    sort(arr.begin(), arr.end());
    return {arr[k - 1], arr[n - k]};
}
pair<int, int> kthMinMaxElement_Optimised(vector<int> arr, int k)
{
    // concept : heap based approach , time : O(n log  n)  , space : O(n)
    int n = arr.size();
    // concept : heap , min heap , max heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        maxHeap.push(arr[i]);
    }
    int mini = arr[0];
    int maxi = arr[n - 1];

    k--;
    int K = k;
    while (k--)
    {
        minHeap.pop();
        maxHeap.pop();
    }

    return {minHeap.top(), maxHeap.top()};
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

    int k = 3;

    cout << "Brute force Approach ";
    pair<int, int> ans = kthMinMaxElement_Brute(arr, k);
    cout << "Kth minimum and Kth maximum element are " << ans.first << "," << ans.second << endl;

    cout << "Better Approach ";
    cout << "Optimised Approach ";
    pair<int, int> ans2 = kthMinMaxElement_Optimised(arr, k);
    cout << "Kth minimum and Kth maximum element are " << ans2.first << "," << ans2.second << endl;

    return 0;
}
/*
article Link :

*/