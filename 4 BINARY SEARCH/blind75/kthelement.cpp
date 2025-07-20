#include <bits/stdc++.h>
using namespace std;

// Problem :

int kthSmallest_Brute(vector<int> arr, int n, int k)
{
    // brute force Approach-sorting method , time : O(n log n ), space : O(1)

    // sorting approach
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int kthSmallest_Optimised(vector<int> arr, int n, int k)
{
    // optimised approach  : Heap method
    // time : O(n log k), space : O(k)
    priority_queue<int> pq;

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

int main()
{

    vector<int> arr = {3, 1,1,2,4,55,5, 3, 3, 2};
    int n = arr.size();
    int k = 6;
    cout << kthSmallest_Brute(arr, n, k) << endl;
    cout << kthSmallest_Optimised(arr, n, k) << endl;

    return 0;
}

/*
article :
link:

Must try problems:


*/