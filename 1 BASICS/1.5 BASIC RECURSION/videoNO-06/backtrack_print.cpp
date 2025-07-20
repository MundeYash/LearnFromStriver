#include <iostream>
using namespace std;
// print the 1 to n using the backtracking
void print1toNBack(int i, int n)
{
    // base case
    if (i < 1)
    {
        return;
    }
   
    print1toNBack(i - 1, n);
     cout << i << " ";
}

// print n to 1 using the backtracking

void printNto1Back(int i, int n)
{
    // base case
    if (i >n )
    {
        return;
    }

    
    printNto1Back(i +1, n);
    cout << i << " ";
}


// print the 1 to n using the backtracking
void print1toN(int i, int n)
{
    // base case
    if (i > n)
    {
        return;
    }
    cout << i << " ";
    print1toN(i + 1, n);
}

// print n to 1 using the backtracking

void printNto1(int i, int n)
{
    // base case
    if (i < 1)
    {
        return;
    }

    cout << i << " ";
    printNto1(i - 1, n);
}
int main()
{
    int n = 10;
    print1toN(1, n);
    printNto1(10, n);
    cout<<endl;
    print1toNBack(10,n);
    printNto1Back(1,n);

    return 0;
}