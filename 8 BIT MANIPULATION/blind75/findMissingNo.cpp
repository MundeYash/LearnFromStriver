#include <bits/stdc++.h>
using namespace std;
// Find the missing no :Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

int missingNumberOptimised(vector<int> &nums)
{
    // concept : xor operation
    // time : O(n) , space : O(1)
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res ^= nums[i];
        res ^= i;
    }
    res ^= n;
    return res;
}

int missingNumberBrute(vector<int> nums)
{

    // time : O(n) , space : O(n)
    int n = nums.size();
    vector<int> count(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (count[i] == 0)
            return i;
    }
    return -1;
}
int main()
{
    vector<int> nums = {3, 0, 1};
    cout << "The missing no is : " << missingNumberBrute(nums) << endl;
    cout << "The missing no is : " << missingNumberOptimised(nums) << endl;

    return 0;
}

/*

https://leetcode.com/problems/missing-number/description/        (done)
*/