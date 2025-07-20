#include<iostream>
using namespace std ; 
//EUCLEDIAN ALGORITHM(For calculating the greatest common divisor in Log(n))

int eucledianGCD(int a , int b ){
    while(a>0 and b>0 ){
        if (a>b){
            a = a%b ;
        }
        else{
            b = b% a;
        }
    }
    if (a==0){
        return b ;
    }
    else{
        return a ;
    }
}
int main (){
    int a , b ; 
    cin>> a>> b;
    cout<<"The GCD value is :  "<<eucledianGCD(a,b)<<endl;

    return 0 ;
}