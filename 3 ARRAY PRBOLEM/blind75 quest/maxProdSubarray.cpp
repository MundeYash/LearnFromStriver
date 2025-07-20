#include <bits/stdc++.h>
using namespace std;
// Question Name : Maximum Product Subarray : find the maximum product of the subarray in the given array

int maxProduct_Optimised2(vector<int>arr ){

}
int maxProduct_Optimised(vector<int>arr ){
    // Concept : prefix Product or Suffix product ,Time : O(n) , space : O(n-> no of elements in the array )
    int n = arr.size();
    int ans = INT_MIN ; 
    int prefix =1 , suffix =1 ;
    for (int i=0 ;i<n;i++ ){
        if (arr[i]==0 ){
            // reinitialize the prefixProduct and suffix product to 1 jsut due to spliting of array and creation of new array 
            prefix =1 ; 
            suffix =1 ;
            
        }
            prefix *= arr[i]; 
            suffix *= arr[(n-i-1)];

            ans = max(ans , max(prefix ,suffix));
    }
    return ans;
}



int maxProduct_better(vector<int> arr)
{
   // Better   approach : Explore all the possible subarrays and insted of calculating the sum from scratch, add current value to previous sum
    //,time : O(n^2) , space :O(1)
    int max_sum = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {

            prod *= arr[j];

            // update the max_sum
            max_sum = max(max_sum, prod);
        }
    }
    return max_sum;
}

int maxProduct_brute(vector<int> arr)
{
    // Brute Force approach :Concept :  Explore all the possible subarrays ,time : O(n^3) , space :O(1)
    int max_sum = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            // subarray creation and sum finding
            int prod = 1;
            for (int k = i; k <= j; k++)
            {
                prod *= arr[k];
            }

            // update the max_sum
            max_sum = max(max_sum, prod);
        }
    }
    return max_sum;
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
    int ans = maxProduct_brute(arr);
    cout << "Maximum product of the subarray is : " << ans << endl;
    cout << "Maximum product of the subarray is : " << maxProduct_better(arr) << endl;
    cout << "Maximum product of the subarray is : " << maxProduct_Optimised(arr) << endl;
    return 0;
}
/*
article Link :https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/

//Problem Link : https://leetcode.com/problems/maximum-product-subarray/description/
https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card




*/