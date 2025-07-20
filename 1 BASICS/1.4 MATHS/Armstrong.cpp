#include<bits/stdc++.h>
using namespace std ; 
int  count (int n ){
    int copy = n ; 
    int ld=0 , ans=0 ; 
    while (copy>0){
        ld = n%10 ; 
        ans ++ ; 
        copy = copy/10 ; 

    
    }
     return ans     ;
}
// Program for Checking whether a number is armstrong number or not 

int main (){
    int n ; 
    cin>> n ; 
int ld=0 , ans=0 ; 
    int copy = n ; 
    while (copy>0){
        ld  = copy %10 ; 
        ans = ans + pow(ld,count(n));
        copy = copy /10 ; 
        
    }
     if (n == ans ){
        cout<<"Yes "<<endl;
     }
     else {
        cout<<"No"<<endl;
     }
    return 0 ; 
}