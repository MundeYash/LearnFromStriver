#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Minimum and maximum element in the array 
pair<int , int > minMaxElement_Brute(vector<int>arr ){
    int n = arr.size() ; 
    // concept : sorting  , time : O(n log n ) , space : O(1)
    sort(arr.begin() , arr.end()) ; 
    return {arr[0] , arr[n-1]} ;


}
pair<int , int > minMaxElement_Optimised(vector<int>arr ){
    // concept : Linear search , time : O(n)  , space : O(1)
    int n = arr.size() ; 
    int mini = INT_MAX ; 
    int maxi = INT_MIN ; 
    for (int i=0 ;i<n ;i++ ){
        mini = min(mini , arr[i]) ; 
        maxi = max(maxi , arr[i]) ; 
    }
    return {mini, maxi};
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
    printArray(arr);


    cout<<"Brute force Approach " ;
    pair<int , int  > ans = minMaxElement_Brute(arr);
    cout<<"Mimimum and maximum element are "<< ans.first <<","<<ans.second <<endl;
    cout<<"Better Approach ";
    cout<<"Optimised Approach ";
      pair<int , int  > ans2= minMaxElement_Optimised(arr);
        cout<<"Mimimum and maximum element are "<< ans2.first <<","<<ans2.second <<endl;
    
    return 0 ;
}
/*
article Link : 

*/