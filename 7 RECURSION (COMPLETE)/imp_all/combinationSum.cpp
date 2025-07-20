#include <bits/stdc++.h>
using namespace std;
//: combinational Sum : Given an array of integer and we need to find the number of possible combination from the elements whose sum will be equal to the target value.

// brute force Approach :

// helper function
void solve(int &index, vector<int> arr, int n, int &target, vector<int> &output, vector<vector<int>> &ans)
{
    // base case
    if (index == n)
    {
        if (target == 0)
        {
            ans.push_back(output);
        }

        return;
    }
    // recursive case
    if (index < n)
    {
        // pick the element
        if (arr[index] <= target)
        {
            output.push_back(arr[index]);
            target = (target - arr[index]);
            solve(index, arr, n, target, output, ans);
            target = (target + arr[index]);
            output.pop_back(); // backtrack
        }

        // not pick the element (means move to next index )
        index++;

        solve(index, arr, n, target, output, ans);

        index--;
    }
}
vector<vector<int>> combinationSum(vector<int> arr, int n, int target)
{
    vector<vector<int>> ans;

    // time : O(2^n) , space : O(n)
    int index = 0;
    vector<int> ds;

    solve(index, arr, n, target, ds, ans);
    return ans;
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
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printArray(arr);
    int n = arr.size();
    int target = 7;
    vector<vector<int>> res = combinationSum(arr, n, target);
    if (res.size() == 0)
        cout << "No array found ";

    for (auto x : res)
    {

        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
article Link :https://takeuforward.org/data-structure/combination-sum-1/
https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rQ6cnlaHRMuOp4H_D-7hwP&index=1
Problem Link : https://leetcode.com/problems/combination-sum/


*/