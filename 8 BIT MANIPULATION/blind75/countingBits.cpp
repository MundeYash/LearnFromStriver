#include <bits/stdc++.h>
using namespace std;
// Given an integer we need to return an array of size of (n+1 ) where each index represent count of number of set bits present in it
vector<int> countBits(int n)
{
    // time : O(n) , space : O(n)
    vector<int> res(n + 1, 0);
    res[0]=0;
    for (int i = 1; i <= n; i++)
    {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}
int countSetBits(int n)
{
    // time : O(n) ,space : O(1)
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << "The number of set bit present in " << n << " Is : " << countSetBits(n) << endl;
    vector<int> res = countBits(n);
    for (int i = 0; i <= n; i++)
    {
        cout << i << ":" << res[i] << " ";
    }
    cout << endl;
    return 0;
}
/*

https://leetcode.com/problems/counting-bits/description/
*/