#include<iostream>
using namespace std ; 

// IInd method for finding the GCD using EUCLIDIAN Algorithm 
long long Eculdian (int a , int b ){//T:O(log n )
    // via Recurison 
    while (a>0 and b>0 ){
        if (a>b ){
            a = a%b ;
        }
        else {
            b = b%a ;
        }
    }
    if (a==0){
        return b ;
    }
    return a ;
}
long long gcd(int a , int b ){
    //Ist method 
    for (int i=min(a,b) ;i>=0 ;i--){//T:O(N)
        if (a%i==0 and b%i==0){
            return i ;
        }
    }
    return -1;
}
int main (){
    int a, b ; 
    cin>> a>> b ; 
    //lcm* gcd = (a*b)
    long long Gcd= gcd(a,b) ;
    long long lcm = (a*b)/(Gcd);
    cout<<"The GCD/HCF is :"<<(Gcd)<<endl;
    cout<<"The GCD/HCF is :"<<(Eculdian(a,b))<<endl;
    cout<<"The LCM is : "<<lcm<<endl;

    return 0 ;
}