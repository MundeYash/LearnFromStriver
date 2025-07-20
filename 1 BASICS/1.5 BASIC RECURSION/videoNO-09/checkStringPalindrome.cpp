#include <iostream>
using namespace std;
// PROBLEM: Checking a string is Palindrome or not
bool checkPalindrome(string s, int i, int n)
{
    // base condition
    if (i >= (n / 2))
    {
        return true;
    }
    if (s[i] != s[n - i - 1])
    {
        return false;
    }
    checkPalindrome(s, i + 1, n);
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    if (checkPalindrome(s, 0, n ))
    {
        cout << "Palindrome hai " << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}