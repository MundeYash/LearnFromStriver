#include <bits/stdc++.h>
using namespace std;
// Problem : given an array and we need to find the kth Largest elment in it
int kthLargest_brute(vector<int> arr, int k)
{
    // brute force approach : concept - sorting , time :o(n log n ) , space : O(1)

    int n = arr.size();
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int kthLargest_Optimised(vector<int> arr, int k)
{
    // Optimised approach : concept - min heap , time : O(n log k ) , space : O(k)
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq; // solving using the min- heap
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() > k)
    {
        pq.pop();
    }
    return pq.top();
}
int kthLargest_Optimised2(vector<int> arr, int k)
{
    // Optimised approach : concept - max heap , time : O(n log k ) , space : O(k)
    int n = arr.size();
    priority_queue<int> pq; // solving using the max- heap
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    k--;
    while (k--)
    {
        pq.pop();
    }
    return pq.top();
}
void print(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int n = arr.size();
    int k = 3;
    cout << kthLargest_brute(arr, k) << endl;
    cout << kthLargest_Optimised(arr, k) << endl;
    cout << kthLargest_Optimised2(arr, k) << endl;

    return 0;
}
/*
Article: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
Problem link :https://leetcode.com/problems/kth-largest-element-in-an-array/description/        (done)




simililar Question :

*/