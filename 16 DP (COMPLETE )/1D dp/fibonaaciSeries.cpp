#include <bits/stdc++.h>
using namespace std;

// Fibonacci Series  :Given a number and we need to find th nth fibonacci number  , in fibonacci series each number of sum of previous two numbers

int fibonacci_Dp_Memoiazation(int n)
{
    /*
        Time : O(n)
        space : O(n)
        concept - memoization
     */
    // step 1: create dp array
    vector<int> dp(n + 1, -1);

    // work for the base case
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    // check before evaluating if it is calculated or not
    if (dp[n] != -1)
        return dp[n];

    // store the answer before returning
    return dp[n] = fibonacci_Dp_Memoiazation(n - 1) + fibonacci_Dp_Memoiazation(n - 2);
}
int fibonacci_Recursive(int n)
{

    /*
        Time : O(2^n)
        space : O(n)-> recursive stack space
        concept - simple recursion

     */
    // base case
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    // recursive
    return fibonacci_Recursive(n - 1) + fibonacci_Recursive(n - 2);
}

int main()
{
    int n = 19;
    cout << fibonacci_Recursive(n) << endl;
    cout << fibonacci_Dp_Memoiazation(n) << endl;

    return 0;
}