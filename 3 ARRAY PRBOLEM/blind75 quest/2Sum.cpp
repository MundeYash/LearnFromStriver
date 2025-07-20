#include <bits/stdc++.h>
using namespace std;
// find all the all pair in the array whose sum is equal to target value


/*
Note and some important conclusion : 
1. Use two loops / explore all pair method if we have to consider the duplicate values 
2. Use sorting and two pointer or Hashing method if we have to consider the unique values
3.

*/
vector<pair<int, int>> PairSum_optimised2(vector<int> arr, int n, int target)
{

    // Approach 3 : optimised :concept : Hashing ,  (finding all the pairs  )

    vector<pair<int, int>>  ans;
    unordered_map<int, int> mp; // value and indexes
    // indexes we are storing
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int more = target - arr[i];
        if (mp.find(more) != mp.end())
        {
            // means second value of pair is finded
            auto it = mp.find(more);
            int first = it->second;
            int second = i;
            ans.push_back({first, second}); // assuming 0 based indexing
            mp.erase(it);                   // remove the pair from map, for duplicate case handling 
            
        }
        mp[curr] = i;
    }

    return ans;
}
vector<pair<int, int>> Pairsum(vector<int> arr, int n, int target)
{
    // Apprach 2 :concept - sorting approach + Two pointer approach , optimised : (valid for pair value cases ) if we don't have restricion in indexes
    // time : O (n log n ) , space : O(1)
    vector<pair<int, int>> ans;
    sort(arr.begin(), arr.end()); //
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == target)
        {
            ans.push_back({arr[left], arr[right]});
            left++;
            right--;
        }
        else if (arr[left] + arr[right] < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return ans;
}

vector<pair<int, int>> PairSum_Brute(vector<int> arr, int n, int target)
{
    // Approach 1 : Brute force , concept (two loop exploring all possible pairs ), time : O(n^2), space : O(1)
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back({arr[i], arr[j]});
            }
        }
    }
    return ans;
}

// function to print all the pairs 
void printPairs(vector<pair<int, int>> ans)
{
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }
}
int main()
{
    vector<int> arr = {3, 13, 5, 11, 10, 92};
    int target;
    cout << "Enter target value ";
    cin >> target;
    // vector<pair<int , int>> ans = Pairsum(arr, arr.size(), target);
    vector<pair<int, int>> ans = PairSum_Brute(arr, arr.size(), target);
    vector<pair<int, int>> ans2 = PairSum_optimised2(arr, arr.size(), target);
    if (ans.size() == 0)
        cout << "NO pair exists ";
    else
        cout << "Yes ";
    printPairs(ans);
    printPairs(ans2);
    return 0;
}

/*

Try Problems : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

 2: https://leetcode.com/problems/two-sum/description/
 https://www.interviewbit.com/problems/2-sum/           solved


*/