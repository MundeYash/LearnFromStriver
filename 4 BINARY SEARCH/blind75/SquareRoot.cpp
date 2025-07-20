#include <bits/stdc++.h>
using namespace std;
// Square Root : Given a number and we need to find the square root of it
/*
Variation 1 : find nearest square root : means square root of a number withour precision
Variation 2 : find the accurate square root + with upto some decision precision

*/
int squareRoot_Brute(int n)
{
    int ans = -1;
    // brute force : linear traversal and check
    // time : O(n), space : O(1)
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
double squareRootPrecise_Optimised(int n, int precision, int tempSolution)
{
    double ans = tempSolution;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; (j * j) < n; j += factor)
        {
            ans = j;
        }
    }

    return ans;
}
int squareRoot_Optimised(int n)
{
    // optimsed aproach : concept - binary search ,
    // time : O(logn), space : O(1)
    // square root without precision or nearest number square root
    int start = 0, end = n;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int value = (mid * mid);
        if (value == n)
        {
            return mid;
        }
        else if (value < n)
        {
            // store smaller and find the nearest one
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{

    int n = 101;
    cout << squareRoot_Brute(n) << endl;
    int value = squareRoot_Optimised(n);
    cout << squareRoot_Optimised(n) << endl;
    int precision = 3;
    cout << squareRootPrecise_Optimised(n, precision, value) << endl;

    return 0;
}

/*
Article :
link

must try
https://www.geeksforgeeks.org/problems/square-root/1


https://www.naukri.com/code360/problems/square-root-decimal_1095655?interviewProblemRedirection=true&search=square%20&leftPanelTabValue=SUBMISSION (done)
*/