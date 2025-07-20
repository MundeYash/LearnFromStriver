#include <bits/stdc++.h>
using namespace std;
// given an array and target  ,we need to find the unique triplets whose sum is equal to the target
vector<vector<int>> Optimised(vector<int> arr, int target)
{
    // concept : modified version of sorting and two pointer approach

    // time complexity of this code : O(n^2), space : O(1)
    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == target)
            {
                vector<int> temp = {arr[i], arr[l], arr[r]};
                s.insert(temp);
                l++;
                r--;
            }
            else if (arr[i] + arr[l] + arr[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    for (auto x : s)
    {
        ans.push_back(x);
    }
    return ans;
}

vector<vector<int>> better(vector<int> arr, int target)
{
    // concept : hashing and set data structure
    // time complexity of this code : O(n^2), space : O(n)
    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        // hashset creation for finding third element
        set<int> update;
        for (int j = i + 1; j < n; j++)
        {
            int third = target - (arr[i] + arr[j]);
            if (update.find(third) != update.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }

            // if third element is not finded insert it in the hashset
            update.insert(arr[j]);
        }
    }
    for (auto x : s)
    {
        ans.push_back(x);
    }
    return ans;
}

vector<vector<int>> brute(vector<int> arr, int target)
{ // time complexity of this code :    O(n^3)

    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    // one valid pair is finded
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    for (auto x : s)
    {
        ans.push_back(x);
    }

    return ans;
}

// function to print all the triplets
void printTriplets(vector<vector<int>> ans)
{
    if (ans.size() == 0)
        cout << "No triplet found \n";
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> arr = {1, 4, 1, 4, 45, 6, 8,8, 10};
    int target = 13;

    vector<vector<int>> ans = brute(arr, target);

    vector<vector<int>> ans2 = better(arr, target);
    vector<vector<int>> ans3 = Optimised(arr, target);

    cout << "\nFor Brute Force : ";
    printTriplets(ans);
    cout << "\nFor Better  : ";
    printTriplets(ans2);

    cout << "\nFor Optimised Force : ";
    printTriplets(ans3);
    return 0;
}

/*
article : https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/


must try question :
https://www.interviewbit.com/problems/3-sum/
https://www.geeksforgeeks.org/problems/3-sum-closest/1
https://www.geeksforgeeks.org/problems/three-sum-closest/1


https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

*/