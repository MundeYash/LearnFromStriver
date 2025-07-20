#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Reverse the given array 

vector<int> reverseArray_Brute(vector<int>arr ){
    int n = arr.size() ; 

    // use another array for reverse, time : O(n) , space : O(n)
    vector<int>temp ; 
    for(int i = n-1 ; i>=0 ; i--){
        temp.push_back(arr[i]) ; 
    }
    return temp ; 
}


// 
vector<int> reverseArray_Optimised(vector<int>arr ){
    // concept  : two pointer , time : O(n) , space : O(1)
    int n = arr.size()  ; 
    int s =0 , e = n-1 ; 
    while (s<e ){
        swap(arr[s], arr[e]) ; 
        s++ ; 
        e-- ; 
    }
    return arr ;
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
    vector<int>ans = reverseArray_Brute(arr ) ; 
    printArray(ans);
    cout<<"Better Approach ";
    cout<<"\nOptimised Approach ";
    vector<int>ans2 = reverseArray_Optimised(arr) ;
    printArray(ans2) ;
    
    return 0 ;
}
/*
article Link : 

*/