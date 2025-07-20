#include <bits/stdc++.h>
using namespace std;
// Problem : given an 2d vector , having different arrays and we need to merge these array make them sorted
vector<int> mergerKsortedArrays_brute(vector<vector<int>> arr, int n)
{
    vector<int> ans;
    // Brute force approach
    // concept : sorting , time : O(n* m log m ) , space : O(n*m)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            ans.push_back(arr[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
vector<int> mergerKsortedArrays_Optimised(vector<vector<int>> arr, int n)
{
    // concept : priority_queue , time : O(n* log n ) , space : O(n)
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            pq.push(arr[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
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
    vector<vector<int>> arr = {{1, 1, 1, 2, 2, 3}, {3, 41, 1, 10, 11}, {2, 1, 3, 11, 10, 9}};
    int n = arr.size();
    int k = 2;
    vector<int> ans = mergerKsortedArrays_Optimised(arr, k);
    vector<int> ans2 = mergerKsortedArrays_brute(arr, k);
    cout << "Optimised-:";
    print(ans);
    cout << "Brute Force:";
    print(ans2);
    return 0;
}
/*
Article
Problem link :
https://www.interviewbit.com/problems/merge-k-sorted-arrays/        (done)

simililar Question :

*/