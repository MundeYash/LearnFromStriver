#include <iostream>
using namespace std;
// program to print the same name n times using the recursion
void print(int n)
{
    if (n == 0)
    { // base case ;
        return;
    }
    cout << "hello world"
         << "\n"; // recursive case
    print(n - 1);
}
int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}