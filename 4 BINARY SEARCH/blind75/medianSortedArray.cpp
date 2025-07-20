#include <bits/stdc++.h>
using namespace std;
// Question Name : Find the median of Two sorted array of equal size  / unequal size  ( odd no of elements  / even number of elements )
void printArray(vector<int>arr );
int arrayMedian(vector<int> arr, int n)
{
    // concept : sorting , formula of median concept

    // step 1 : sort the array
    sort(arr.begin(), arr.end());

    printArray(arr);

    // step 2 : if n is even then median is average of two middle elements
    if (n % 2 == 0)
    {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }
    else
    {
        // if n is odd than only single median value exists
        return arr[n / 2];
    }
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
    vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    printArray(arr);

    cout << "Brute force Approach ";
    cout << "Better Approach ";
    cout << "Optimised Approach ";
    cout << " Median value of the array is : " << arrayMedian(arr, arr.size());

    return 0;
}
/*
article Link :
https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

*/