#include <iostream>
using namespace std;
// Finding the factorial of a number

// solving via the loops
int factVialoops(int n)
{
    long long int ans = 1;
    for (int i = n; i >= 1; i--)
    {
        ans *= i;
    }
    return ans;
}

//*** solving via RECURSION
int factMethod1(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * (factMethod1(n - 1));
}

// forward approach 
void factMethod2 (int n , int value ){
    if (n<1){
        cout<<value<<endl;
        return ;
    }
    factMethod2(n-1 , value = value*n);
}


int main()
{
    int n;
    cin >> n;
    cout << factVialoops(n) << endl;
    cout << factMethod1(n) << endl;
    factMethod2(n,1);
    

    return 0;
}