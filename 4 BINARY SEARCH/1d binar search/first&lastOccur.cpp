#include<bits/stdc++.h>
using namespace std ; 
//Problem : given an  sorted array array , we need to find the first occurence and last occurence of an element

// naive approach : linear search , time : O(n) , space : O(1)
pair<int, int> firstNlastOccur_Brute(vector<int>arr , int n, int target ){
    // concept : linear search , time : O(n), space : O(1)
    int firstOccur = -1 , lastOccur = -1 ; 
    for (int i = 0 ; i<n ; i++){
        if (arr[i] == target){
            firstOccur = i ; 
            break ; 
        }
    }
    for (int i = n-1 ; i>=0 ; i--){
        if (arr[i] == target){
            lastOccur = i ; 
            break ; 
        }
    }
    return {firstOccur, lastOccur} ; 
}

int firstOccur(vector<int>arr , int n , int target ){
    // concept : binary search , time : O(log n ), space : O(1)
    int s = 0 , e = n-1 ; 
    int ans = -1 ; 
    while (s<=e){
        int mid = s + (e-s)/2 ; 
        int value = arr[mid]; 
        if (value == target ){
            ans = mid ; 
            //further check on left side 
            e = mid - 1; 
        }
        else if (value >target){
            // move to left side 
            e = mid - 1; 
        }
        else {
            // move to right side 
            s = mid + 1; 
        }
    }
    return ans ; 
}
int lastOccur(vector<int>arr , int n , int target ){
    // concept : binary search , time : O(log n ), space : O(1)
    int s = 0 , e = n-1 ; 
    int ans = -1 ; 
    while (s<=e){
        int mid = s + (e-s)/2 ; 
        int value = arr[mid]; 
        if (value == target ){
            ans = mid ; 
            //further check on right side 
            s = mid + 1;
           
        }
        else if (value >target){
            // move to left side 
            e = mid - 1; 
        }
        else {
            // move to right side 
            s = mid + 1; 
        }
    }
    return ans ; 
}
pair<int, int> firstNlastOccur_Optimised(vector<int>arr , int n, int target  ){
    // concept : binary search , time : O(log n ), space : O(1)
    int first = firstOccur(arr, n, target);
    int last = lastOccur(arr, n, target);
    return {first, last} ;

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
vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
int n = arr.size();
int target =5 ;
    printArray(arr);

    pair<int,int> ans = firstNlastOccur_Brute(arr, n,target);
    cout << "First Occurence : " << ans.first << " Last Occurence : " << ans.second << endl;
    pair<int,int> ans2 = firstNlastOccur_Optimised(arr, n , target);
    cout << "First Occurence : " << ans2.first << " Last Occurence : " << ans2.second << endl;

    return 0 ;
}
/*
article Link : 

*/