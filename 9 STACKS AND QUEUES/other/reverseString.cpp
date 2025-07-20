#include <bits/stdc++.h>
using namespace std;
// Question Name : Reverse Given string

// Approach 1: Store somewhere and return it

// Approach 2 : Store in stack and return it
string reverseString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    int i = 0;
    while (!st.empty())
    {
        s[i] = st.top();
        st.pop();
    }
    return s;
}

// Approach 3 : Two pointer approach

// function to print array
void printArray(string arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    // create array and print its value
    string s = "rameshSinghramesh";
    printArray(s);
    string ans = reverseString(s);
    printArray(ans);
    return 0;
}
/*
article Link :

*/