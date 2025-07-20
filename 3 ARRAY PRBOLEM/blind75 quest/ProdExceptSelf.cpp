#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Product of array except the self (Multiplication of array elements except the self )

vector<int> solution_optimised(vector<int>arr ){
    // concept : prefixProduct and suffix Product 
    // prefix Product and suffix Product concept will be used 
    int n = arr.size();
    int pref=1 , suff =1 ;
    vector<int> prefixProd (n);; 
    vector<int> suffixProd(n);
    vector<int> ans  (n);


    prefixProd[0] =1 ; 
    suffixProd[n-1] = 1;
    
    for(int i= 1 ;i<n ;i++ ){
        pref *= arr[i-1];
        prefixProd[i] = pref;
    }
    for (int i=n-2 ;i>=0 ;i-- ){
        suff *=arr[i+1];
        suffixProd[i] = suff ;
    }

    // actual calculation 
    for (int i=0 ;i<n ;i++ ){
        arr[i] = (prefixProd[i] * suffixProd[i]);
    }
    return arr;
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
vector<int> arr = {-1,1,0,-3,3};
    printArray(arr);
    vector<int> ans = solution_optimised(arr);
    printArray(ans);

    
    
    return 0 ;
}
/*
article Link : 
https://leetcode.com/problems/product-of-array-except-self/   
*/