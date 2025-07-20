#include <bits/stdc++.h>
using namespace std;
// Question Name : Balanced parathesis : Given an expression containing brackets and we need check whether the expression is balanced parenthesis expression or not
char counterOpeningBracket(char ch)
{
    char ans;
    if (ch == ')')
        ans = '(';
    else if (ch == ']')
        ans = '[';
    else if (ch == '}')
        ans = '{';
    return ans;
}
bool checkBalancedParenthesis_Optimised(string s)
{
    // concept : stack based approach , time : O(n) , space : O(n) -> stack
    int n = s.size();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            // for opening bracket push to stack
            st.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {

            if (st.empty())
            {
                // means no corresponding opening bracket is present
                return false;
            }

            // means stack has some opening brackter , than check counter opening
            char temp = counterOpeningBracket(ch);
            if (temp != st.top())
                return false;

            // means stack top has corresponding counter opening bracket
            st.pop();
        }
    }

    // now if you have checked for all closing bracket that should be having corresponding opening bracket
    if (!st.empty())
    {
        // some opening bracket left un countered
        return false;
    }
    return true;
}
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
    string s = "(({})) {";
    printArray(s);
    if (checkBalancedParenthesis_Optimised(s))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
/*
article Link :

*/