#include <bits/stdc++.h>
using namespace std;
// Problem : Given an array , we need to find the Kth most frequency element of the array , means kth most occuring element in the array

vector<int> kMostFrequent_Brute(vector<int> arr, int k)
{
    int n = arr.size();
    // Brute force approach
    // concept : map , time : O(n log n ) , space : O(n)
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    vector<pair<int, int>> freq;
    for (auto it : mp)
    {
        freq.push_back({it.second, it.first});
    }
    sort(freq.begin(), freq.end());
    vector<int> ans;
    int N = freq.size();
    for (int i = 0; i < k; i++)
    {

        ans.push_back(freq[N - i - 1].second);
    }
    return ans;
}

vector<int> kMostFrequent_Optimised(vector<int> arr, int k)
{ // Optimised Approach
    // concept : prioirty_queue /max heap, time : O(n* log n ), space : O(n)
    int n = arr.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }

    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
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
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int n = arr.size();
    int k = 2;

    vector<int> ans1 = kMostFrequent_Brute(arr, k);
    vector<int> ans = kMostFrequent_Optimised(arr, k);
    print(ans);
    print(ans1);

    return 0;
}
/*
Article
Problem link :


simililar Question :

*/