#include <bits/stdc++.h>
using namespace std;
// Question Name : Common elements in 3 sorted arrays :
/*
Statement : we are given three sorted arrays and we need to find the common elements in all 3 array and return ans array
*/
vector<int> findCommnonElement_Optimised(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{
    // POINTER APPROACH
    vector<int> ans;
    int s1 = 0, s2 = 0, s3 = 0;

    // Traverse through all arrays using pointers
    while (s1 < arr1.size() && s2 < arr2.size() && s3 < arr3.size())
    {
        // If elements at all three pointers are the same, add to the result
        if (arr1[s1] == arr2[s2] && arr2[s2] == arr3[s3])
        {
            ans.push_back(arr1[s1]);
            // Move each pointer to the next distinct element to avoid duplicates
            int value = arr1[s1];
            while (s1 < arr1.size() && arr1[s1] == value)
                s1++;
            while (s2 < arr2.size() && arr2[s2] == value)
                s2++;
            while (s3 < arr3.size() && arr3[s3] == value)
                s3++;
        }
        // Increment the pointer with the smallest element
        else if (arr1[s1] < arr2[s2])
        {
            s1++;
        }
        else if (arr2[s2] < arr3[s3])
        {
            s2++;
        }
        else
        {
            s3++;
        }
    }

    return ans;
}
vector<int> findCommnonElement(vector<int> a, vector<int> b, vector<int> c)
{
    // concept : hashing , and occurence check
    // time : O(n) , space : O(n)
    vector<int> ans;
    unordered_map<int, pair<bool, pair<bool, bool>>> update;
    for (auto i : b)
    {
        update[i].second.first = true;
        update[i].first = true;
    }
    for (auto i : c)
    {
        update[i].second.second = true;
        update[i].first = true;
    }
    for (auto i : a)
    {
        if (update.find(i) != update.end())
        {
            // means this value exists in the map
            auto it = update.find(i);
            if (update[i].second.first == true && update[i].second.second == true && update[i].first == true)
            {
                ans.push_back(i);
                update[i].first = false;
            }
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
    vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100, 100};
    sort(arr.begin(), arr.end());
    printArray(arr);
    vector<int> arr2 = {1, 3, 1, 4, 5, 61, 7, 19, 10, 100, 100};
    sort(arr2.begin(), arr2.end());
    printArray(arr2);
    vector<int> arr3 = {13, 9, 0, 7, 62, 19, 10, 100, 100};
    sort(arr3.begin(), arr3.end());
    printArray(arr3);

    cout << "Brute force Approach ";
    cout << "Better Approach ";
    vector<int> ans = findCommnonElement(arr, arr2, arr3);
    printArray(ans);

    cout << "Optimised Approach ";

    vector<int> ans2 = findCommnonElement_Optimised(arr, arr2, arr3);
    printArray(ans2);
    return 0;
}
/*
article Link :

*/