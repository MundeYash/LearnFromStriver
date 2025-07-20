#include <iostream>
using namespace std;
// PROBLEM : FIRST N FIBONACCI NUMBERS

// solving via the loops
int fibonacciLoops(int n ){
    if (n==0||n==1){
        return n ;
    }
    int a=0 , b=1 ,ans =0 ;
for (int i=2 ;i<=n ;i++){
    ans = (a+b);
    a= b ; 
    b= (ans);


}
return ans ;

}
//*******************TIME COMPLEXITY :O(2^N)*******************
int fibonacciRec(int n)
{
    if (n == 0 || n == 1)
    {

        return n;
    }
    return (fibonacciRec(n - 1) + fibonacciRec(n - 2));
}
int main()
{
    int n;
    cin >> n;
    cout << fibonacciRec(n) << endl;
    cout << fibonacciLoops(n) << endl;
    return 0;
}