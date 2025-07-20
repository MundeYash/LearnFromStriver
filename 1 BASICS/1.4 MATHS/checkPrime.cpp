#include<iostream> 
using namespace std ; 
//Checking a number is prime or not 
bool checkPrime(int n ){
    for (int i=2 ;i<n ;i++){
        if (n%i==0){
            return false ;
        }
    }
    return true ;
}

int main(){
    int n ; 
    cin>>n ; 
    if (checkPrime(n)){
        cout<<"Prime"<<endl;
    }
    else {
        cout<<"Non Prime";
    }

    return  0 ;
}