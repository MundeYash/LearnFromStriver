#include <bits/stdc++.h>
using namespace std;
// Question : Book Allocation Problem : Allocate n number of books to m students such that maximum number of books allocated to each child is minimum
/*
You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
*/
bool isPossible(vector<int> arr, int n, int m, int threshold)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if ((pageSum + arr[i]) <= threshold)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            pageSum = arr[i]; // reintialize page sum for next student
            if (studentCount > m || (arr[i] > threshold))
            {
                return false;
            }
        }
    }
    return true;
}
int allocateBooks(vector<int> arr, int n, int m)
{
    // concept : binary search , time : O(log n ) , space :O(1);

    // genrating search space range
    // Edge case: If students are more than the books, return -1
    if (m > n) return -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // apply binary search
    int start = 0, end = sum;
    int ans = INT_MAX;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            // if possible then store the ans and try to find the minimum
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            // if not possible then try to increase the mid value , as not solution will exists on left side
            start = mid + 1;
        }
    }
}
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 5;
    cout << allocateBooks(arr, n, m);

    return 0;
}

/*
Article :
link

must try
https://www.naukri.com/code360/problems/ayush-gives-ninjatest_1097574?interviewProblemRedirection=true&practice_topic%5B%5D=Binary%20Search
*/