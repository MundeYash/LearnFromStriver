#include <bits/stdc++.h>
using namespace std;

// function to check whether a array contain duplicate or not
bool approach2(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        
    }
}

// function to return all the duplicate elements in the array
vector<int> approach3(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        if (mp.find(value) == mp.end())
        {
            // not founded
            mp[arr[i]]++;
        }
        else
        {
            ans.push_back(value);
        }
    }
    return ans;
}

// function to check whether a array contanis duplicate values or not
bool brute1(vector<int> arr, int n)
{
    // time : O(n^2) , space : O(1)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

bool brute2(vector<int> arr, int n)
{
    // time : O(n) , space : O(n)
    // concept : sorting approach
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return true;
    }
    return false;
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
    vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    printArray(arr);
    if (brute1(arr, arr.size()) && brute2(arr, arr.size()))
    {
        cout << "Yes ";
    }
    else
    {
        cout << "No ";
    }
    cout << endl
         << "Duplicate elements in the array are : ";
    vector<int> ans = approach3(arr);

    printArray(ans);
    return 0;
}

/*
Article : https://takeuforward.org/data-structure/contains-duplicate-check-if-a-value-appears-atleast-twice/


Homework trye : "https://www.interviewbit.com/problems/find-duplicate-in-array/              (rem)"
https://www.interviewbit.com/coding-interview-questions/#status[]=attempted&status[]=unsolved&text=duplicate

https://leetcode.com/problems/contains-duplicate-iii/ 

*/