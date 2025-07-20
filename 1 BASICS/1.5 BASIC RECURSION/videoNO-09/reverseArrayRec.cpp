#include<iostream>
using namespace std ;
// PROBLEM: reverse the given array 
// solving via the loops 
void reverseArrayLoops (int a [] ,int n  ){
    int s=0 , e=n-1 ; 
    while (s<=e){
        swap(a[s++], a[e--]) ;
    }
}



// function for printing the array 
void print(int a[] , int n){
    for (int i =0 ;i<n ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// Reversing the given array using the recursion 

void reverseRec(int a[], int s, int e ){
    // base case 
    if (s>=e){
        return ;
    }
    swap(a[s++] ,a [e--]) ;
    reverseRec(a,s,e);
}

// **** OPTIMISED REVERSE ARRAY ******(solving using the single iterator )
void reverseArrayOptimised(int a[] , int i , int n ){
    if (i>=(n/2)){
        return ;
    }
    swap(a[i] , a[n-i-1]);
    reverseArrayOptimised(a,i+1 , n);
}

int main(){
    int a[] ={2,3,5,6,1,10} ; 
    int n = sizeof (a) /sizeof (int);
    print(a,n) ;
    // reverseArrayLoops(a,n);
    // reverseRec(a,0,n-1);
    reverseArrayOptimised(a,0,n-1);
    print(a,n);

    return 0 ;
}