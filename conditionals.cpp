#include<iostream>
using namespace std ; 
int main (){
    // basic format for marks display using if and else ladder 

    // int marks  ;
    // cin>> marks  ; 

    // if (marks<25 ){
    //     cout<<"F";
    // }
    // else if (marks <=44 ){
    //     cout<<"E";
        

    // }
    // else if (marks<=49 ){
    //      cout<<"D";
    // }
    // else if (marks <=59 ){
    //     cout<<"C";
        

    // }
    // else if (marks <=79 ){
    //     cout<<"B";
        

    // }
    // else if (marks <= 100 ){
    //     cout<<"A";
        

    // }


    // Example -02 Age and result 

    int age ; 
    cin>> age ;
    if (age<18){
        cout<<"Not Eligible for Job " ; 
    }
    
     else if ( age <=54  ){
        cout<<"eligible for job " ;
    }
     else if (age <= 57  ){
        cout<<"eligible for job  But retirement soon !" ;
    }
    else  {
        cout<<"Retirement time " ; 
    }
    return 0 ; 
}