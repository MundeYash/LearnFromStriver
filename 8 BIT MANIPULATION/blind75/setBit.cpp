#include<bits/stdc++.h>
using namespace std; 
// Given an integer we need count the number of set bits present in it 
int countSetBits(int n){
    // time : O(n) ,space : O(1)
    int count = 0 ;
    while(n){
        n = n & (n-1) ;
        count++ ;
    }
    return count ;
}

int main (){
    int n ; 
    cin>> n ; 
    cout<<"The number of set bit present in "<<n <<" Is : "<<countSetBits(n)<<endl;
    return 0 ;
}
/*


*/