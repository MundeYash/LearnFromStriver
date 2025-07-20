#include<bits/stdc++.h>
using namespace std ; 
// Sum of Two integers : Given Two integer a and b , we need to find the sum of two integers without using the operators + and -.
int sumInt(int a , int b ){
    // concept : bitwise xor operation 
    
    while (b){
        int carry = a & b ;
        a = a ^ b ;
        b = carry << 1 ;
    }
    return a ;
}
int main (){
    int a = 1 , b = 2 ;
    while(b != 0){
        int carry = a & b ;
        a = a ^ b ;
        b = carry << 1 ;
    }
    cout << "The sum of two integers is : " << sumInt(a,b) << endl ;
    cout<<"The sum verification :"<<(a+b)<<endl;
    return  0 ;
}

/*

*/