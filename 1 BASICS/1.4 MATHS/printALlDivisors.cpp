#include <iostream>
using namespace std;
void printALLDivisors(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}
bool checkPrime(int n);
// Prinitng all the prime numbers in a range
void printRange(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (checkPrime(i))
        {
            cout << i << " ";
        }
    }
}
bool checkPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    // cin>>a>>b;
    int n = 10;
    //    printRange   (a,b);
    printALLDivisors(n);
    return 0;
}