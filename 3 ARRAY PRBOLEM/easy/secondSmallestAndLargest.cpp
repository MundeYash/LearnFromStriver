#include<bits/stdc++.h>
using namespace std ; 
// finding the second largest and second smallest element in array without sorting 

// second samllest value : 
void getElements (int a[], int n ){
    if (n==0|| n==1 ){
        cout<<"-1, -1 " <<endl;
        // means no second largest and smallest element exits 

    }
    int small, second_small , large, second_large ; 
    small = second_small = INT_MAX  ; 
    large = second_large = INT_MIN ;

    for (int i=0 ;i<n ;i++){
        small = min (small , a[i]);
        large = max(large, a[i]) ;
    }

    // important condition 
    for (int i=0 ;i<n ;i++){
        // for second samllest value 
        if (a[i]<second_small and a[i] != small){
            second_small = a[i];
        }

        //for second largest value 
        if (a[i]>second_large and a[i] != large){
            second_large = a[i] ;
        }
    }

    cout<<"The second smallest value : "<<second_small<<endl;
    cout<<"The second largest  value : "<<second_large  <<endl;
}

int main (){
    // find largest and smallest element the find second largest and second smalles 
    int a[] ={2,21,5,6,10,8};
    int n = sizeof (a)/sizeof (int ) ;
    getElements(a,n);
    return  0 ;
}