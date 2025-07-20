#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Check whether the given array is sorted or not 

bool isSorted(vector<int> arr  ){
    // concept : linear search and condition check , time : O(n) , space : O(1)
    int n = arr.size();
    for (int i=1 ;i<n-1 ;i++ ){
        if (arr[i]<arr[i-1] || arr[i+1]< arr[i])return false ;
    }

    // check for 0th index 
    if (arr[0]>arr[1])return false ;
    // check for last index
    if (arr[n-1]<arr[n-2])return false ;
    return true  ;
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

int main (){
    // create array and print its value 
vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
sort(arr.begin(), arr.end())  ; 
vector<int> arr2 = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    
    cout<<isSorted(arr)<<endl;
    cout<<isSorted(arr2);
    return 0 ;
}
/*
article Link : 

*/