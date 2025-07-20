#include<bits/stdc++.h>
using namespace std ; 
// Minimum in sorted rotated array : given an array which was sorted and rotated at some index , no weed to find the minimum in that sorted rotated array 
// Note : minimum element is nothing but the pivot element


int sortedRotatedMinimum_Brute(vector<int>arr  ){
    // Brute force approach : linear search , time : O(n), space : O(1)
    int n = arr.size();
    int mini = arr[0]; 
    for (int i=0 ;i<n ;i++ ){
        if (arr[i]<mini)mini = arr[i];
    }
    return mini;
}

int sortedRotatedMinimum_Optimised(vector<int>arr ){
    // optimised approach  : concept -binary search and pivot element , 
    // time :O(log n ), space : O(1)
    int ans =-1 ;

    int n = arr.size();
    int start = 0 , end = n-1;
    while (start<end ){
        int mid = (start + (end-start)/2); 
        if (arr[mid]>= arr[0]){
            // pivot element is in right side and you are on upper increasing slope 
            start = mid+1;
        }
        else{
            // pivot element is in left side and you are on lower increasing slope 
            end = mid;
        }
    }
    ans = start ;

    // important condition for strictly increasing array 
    if (arr[ans]>arr[0]){
        ans = 0 ; 
    }
    return arr[ans];
}
int main (){
    vector<int>arr = {4,5,6,7,0,1,2,3} ;   
    cout<<"The minimum element in sorted rotated array is : "<<sortedRotatedMinimum_Brute(arr)<<endl;
    cout<<"The minimum element in sorted rotated array is : "<<sortedRotatedMinimum_Optimised(arr)<<endl;

    return  0 ; 
}

/*
article : https://takeuforward.org/data-structure/minimum-in-rotated-sorted-array/ 

link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/      (done)

must try : 


*/