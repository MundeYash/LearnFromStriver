#include <iostream>
using namespace std ;
// printing the number from n to 1 
void printReverse(int n ){
    // base case 
    if (n==0){
        return ;
    }
    cout<<n<<" ";
    printReverse(n-1);
}
// print the numbers from 1 to n ;
void printStraight(int n ){
    // base case 
    if (n==0){
        return ;
    }
    printStraight(n-1) ; 
    cout<<(n)<<" ";
}
 // Time complexity : O(n) , Space complexity : o(N), due to the internal use of the stack space by the machine
 int main (){
    int n =10 ;
    printReverse(n);
    cout<<endl;
    printStraight(n);
    return 0 ;
 }