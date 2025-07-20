#include <bits/stdc++.h>
using namespace std;
// finding the Missing number in the array  :

// Approach 3: optimal approach
int optimised1_MissingNUm(vector<int> a, int n)
{
    // concept : Sum of n natural number and subtraction , time : O(n) , space : O(1)
    int sum = 0;
    sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n - 1; i++)
    {
        // cout << sum << " ";
        sum = sum - a[i];
    }
    return sum;
}

// Approach 3: optimal approach
int optimised2_MissingNUm(vector<int> a, int n)
{

    // concept : XOR  , time : O(n) , space : O(1)
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sum ^= a[i];
    }
    // xor of first n numbers
    for (int i = 1; i <= n; i++)
    {
        sum ^= i;
    }
    return sum;
}

// Approach 2: Better  approach
int better_MissingNUm(vector<int> a, int n)
{

    // Better Approach: concept : hashmap , time : O(n ) , space : O(n)

    int hashh[n + 1] = {0};
    // updating the values in the hashmap
    for (int i = 0; i < n; i++)
    {
        hashh[a[i]]++;
    }

    // iterate form i=1 to =n  and check which element have 0 value
    for (int i = 1; i <= n; i++)
    {
        if (hashh[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

int bruteForce_MissingNUm(vector<int> a, int k)
{
    // concept  : linear search and bool flag  , time : O(n^2) , space : O(1)
    int n = a.size();

    for (int i = 1; i <= k; i++)
    {
        bool flag = false;

        // applying the linear search for the each element
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            return i;
        }
    }
    return -1;
}

// function for printing the array
void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> a = {{2, 5, 3, 1}};

    int n = 5;
    //    cout<< bruteForce_MissingNUm(a,k)<<endl;
    // cout << better_MissingNUm(a, n) << endl;
    cout << optimised1_MissingNUm(a, n) << endl;
    cout << optimised2_MissingNUm(a, n) << endl;

    return 0;
}