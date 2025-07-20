#include <iostream>
using namespace std;
// Reversing a number
int reverse(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int ld = (n % 10);
        ans = ans * 10 + ld;
        n = n / 10;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << "The reverse of given number is :" << (reverse(n)) << endl;
    return 0;
}