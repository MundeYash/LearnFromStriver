#include <bits/stdc++.h>
using namespace std;
// Question Name : Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

vector<int> majorityElementsNBy2_Brute(vector<int> arr, int n)
{
    vector<int> ans;

    // brute force approach: concept : sorting , time complexity : O(n log n), space : O(1) ;

    // edge case
    if (n == 0 || n == 1)
        return ans;
    int count = 1; // for first element at 0th index
    // step 1 : sort the array
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            // different element is finded and check the count for previous element
            if (count > (n / 2))
            {
                ans.push_back(arr[i - 1]);
            }
            count = 1;
        }
    }

    // check for the last index
    if (count > (n / 2))
    {
        ans.push_back(arr[n - 1]);
    }
    return ans;
}

vector<int> majorityElementsNBy2_Better(vector<int> arr, int n)
{
    // concept : hashing , time : O(n) , space : O(n)
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > (n / 2))
        {
            ans.push_back(it->first);
        }
    }

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
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    printArray(arr);

    cout << "Brute force Approach ->done O(n log n ) sorting based approach ";
    vector<int> ans = majorityElementsNBy2_Brute(arr, arr.size());
    printArray(ans);

    cout << "Better Approach  - > done o(n), O(n) hashing based approach  ";
    ans = majorityElementsNBy2_Better(arr, arr.size());
    printArray(ans);

    cout << "Optimised Approach ";

    return 0;
}
/*
article Link :

*/