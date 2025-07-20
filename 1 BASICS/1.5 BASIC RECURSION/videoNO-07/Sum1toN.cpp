#include <iostream>
using namespace std;
// finding sum of first n natural numbers using the recursion
int Sum1toN(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n) + Sum1toN(n - 1);
}

int method2(int i, int n) // increasing value way (forwarding looping )
{ // 1to n
    // base case
    if (i > n)
    {
        return 0;
    }
    return (i) + method2(i + 1, n);
}
// Method -3 
void printNsum(int n , int sumVal){
    if (n<1){
        cout<<sumVal<<endl;
        return ;
    }
    printNsum(n-1 , sumVal+n);
}
//  find using the loops 
int loopAnsSum(int n ){
    int ans =0 ; 
    for (int i=1 ;i<=n ;i++){
        ans = ans + i ;
    }
    return ans ;
}
int main()
{
    int n = 140;
    // cout<<loopAnsSum(n)<<endl;
    // cout << Sum1toN(n) << endl;
    // cout << method2(1, n) << endl;
     
     printNsum(3,0);
    return 0;
}