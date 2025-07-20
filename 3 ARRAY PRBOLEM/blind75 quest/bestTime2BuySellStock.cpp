#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Given an array denoting the different prices of stocks and we need to find the maximum profit we can earn by purchasing a stock on one day and selling it to other day 
int buySellStock_Optimised(vector<int>arr , int n ){
    // concept : (one loop -> minimum price and whenever stock price will increase we will sell it ) , time : O(N) , space : O(1)
    int maxProfit = 0 ;
    int minPrice = INT_MAX ;
    for (int i=0 ;i<n ;i++ ){
        if (arr[i]<minPrice)minPrice = arr[i];
        else {
            int currProfit = arr[i]-minPrice ;
            if (currProfit>maxProfit)maxProfit = currProfit;
        }
    }
    return maxProfit ;
}

int buySellStock_Brute (vector<int>&arr , int n ){

// concept : (two loops -> whenever stock price will increase we will sell it ) , time : O(N^2 ) , space : O(1)
    int maxProfit = 0 ;
    for (int i=0 ;i<n ;i++ ){
        for (int j=i+1;j<n ;j++ )
        {
            if (arr[j]>arr[i]){
                // stock price is rised and we have got some profit 
                int currProfit = (arr[j]-arr[i]) ; 
                if (currProfit>maxProfit)maxProfit = currProfit;
            }
        }
    }
    return maxProfit ;
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
    cout<<buySellStock_Brute(arr , arr.size())<<endl;
    
    cout<<"NO Better Approach ";
    cout<<"Optimised Approach ";
    cout<<buySellStock_Optimised(arr , arr.size());
    
    return 0 ;
}
/*
article Link : https://takeuforward.org/data-structure/stock-buy-and-sell/


*/