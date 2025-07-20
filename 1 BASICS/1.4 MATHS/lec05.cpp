#include<iostream>
using namespace std ; 
// concept of finding the last digit 

int main (){
    int n ;
    cin>>  n ;
    int x = n  ; 
    // counting the number of digits in a number 
    int counter =0 ;
    while (x>0){
        int ld = x%10;
        cout<<ld<<"->";
        counter++;
        x = x/10 ;
    }
    cout<<"\nNumber of digits in "<<n<<" is: "<<counter<<endl;
    return 0 ; 

}