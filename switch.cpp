#include<iostream>
using namespace std ; 
// this is about switch case statement 

int main (){
    // take day number in input and print corresponding day to it 
    int day ; 
    cin>> day ; 
    switch (day ){
        case 1 : 
        {
            cout<<"Monday ";
             break ; 
        }
        case 2 : 
        {
            cout<<"Tuesday ";
            break ; 
        }
        case 3 : 
        {
            cout<<"Wednesday ";
            break ; 
        }
        case 4 : 
        {
            cout<<"Thursday ";
            break ; 
        }
        case 5 : 
        {
            cout<<"Friday ";
            break ; 
        }
        case 6 : 
        {
            cout<<"Saturday ";
            break ; 
        }
        case 7 : 
        {
            cout<<"Sunday ";
            break ; 
        }
        default: cout<<"Wrong input ";

    }
    return 0 ; 
}