#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Median of un sorted array of different size 
int medianUnsortedArray_Optimised(vector<int>a , vector<int>b ){
    // concept : two pointer and swapping  
    // time : O(n log n ) , space : O(1 ) ; 
    int n = a.size() ;
    int m = b.size() ;
    
    // step 1: sort both arrays 
    sort(a.begin(),a.end()) ; 
    sort(b.begin() , b.end()) ; 
    
    int LeftEnd = n-1 , RightStart =0 ; 
    while (LeftEnd>=0 && RightStart< m ){
        if (a[LeftEnd] > b[RightStart]){
            swap(a[LeftEnd],b[RightStart]);
            LeftEnd-- ; 
            RightStart++ ; 
        }
        else{
            break ; 
        }
    }

    // again apply sorting to make it arrange to sorted order 
    sort(a.begin() ,a.end()) ; 
    sort(b.begin() , b.end()) ; 
    // step 2 : find the median of the merged array
    int k = (n+m ) ; 
    int index = k/2 ;
    if (k % 2 == 0)
    {
        
        // if n is even then median is average of two middle elements
        return (a[k / 2] + a[k / 2 - 1]) / 2;
    }
    else
    {
        // if n is odd than only single median value exists
        return a[k / 2];
    }
}


int medianUnsortedArray_Brute(vector<int>a, vector<int> b ){
    // concept : merge the both array in one array , sort the array and apply median concept 

    // time : O(n log n ) , space : O(n) 


    // step 1 : merge two arrays 
    vector<int> mergedArray ;
    for (int i = 0 ; i < a.size() ; i++){
        mergedArray.push_back(a[i]);
    }
    for (int i = 0 ; i < b.size() ; i++){
        mergedArray.push_back(b[i]);
    }
    // step 2 : sort the array
    sort(mergedArray.begin(), mergedArray.end());
    // step 3 : find the median of the array
    int n = mergedArray.size();
    if (n % 2 == 0)
    {
        return (mergedArray[n / 2] + mergedArray[n / 2 - 1]) / 2;
    }
    else
    {
        // if n is odd than only single median value exists
        return mergedArray[n / 2];
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

int main (){
    // create array and print its value 
vector<int> arr = {32, 1,  32, 3, 11, 10, 100};
    printArray(arr);

vector<int> arr2 = {1, 3, 1, 32,5,91,10,11,20 };
    printArray(arr);


    cout<<"Brute force Approach " ;
    cout<<"Better Approach ";
    cout<<"Optimised Approach ";
    
    return 0 ;
}
/*
article Link : 

*/