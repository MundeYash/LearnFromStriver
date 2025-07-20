#include <iostream>
using namespace std;
// printing the numbers from N to 1 using recursion
void printNto1(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printNto1(n - 1);
}
// method -2
void printNtoOne(int i, int n)
{
    // base case
    if (i < 1)
    {
        return;
    }
    cout << i << " ";
    printNtoOne(i - 1, n);
}
int main()
{
    int n = 10;
    // printNto1(n);
    printNtoOne(10, n);
    return 0;
}