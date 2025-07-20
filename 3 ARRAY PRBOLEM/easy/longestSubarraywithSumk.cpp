#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Subarray with k sum 
/* 
Given an array of integers, find the length of the longest subarray with sum equals to k. 
*/

// function to print array
void printArray(vector<int> arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main (){
    // create array and print its value 
vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    printArray(arr);


    cout<<"Brute force Approach " ;
    cout<<"Better Approach ";
    cout<<"Optimised Approach ";
    
    return 0 ;
}
/*
article Link : 

*/