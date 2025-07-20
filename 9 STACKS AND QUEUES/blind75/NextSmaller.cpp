#include <bits/stdc++.h>
using namespace std;
// Question Name : Next Smaller Element : Given an array of integer , we need to find the next smaller element of each element in the array ,

// Next Smaller element is the first smaller element we encounnter while traversing from left to right
// If no smaller element is found then the next smaller element is -1

// Approach 2: Optimised Approach
vector<int> nextSmaller_Optimised(vector<int> arr)
{
    // concept : stack based approach , time :O(n) , space :O(n)
    int n = arr.size();
    stack<int> st;
    // right to left  traversal because of (finding next value )
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        // conditiion 1 : stack is empty no smaller element exists for it
        if (st.empty())
        {
            arr[i] = -1;
        }

        // condition 2 : stack top contain answer or not
        else if (!st.empty() && st.top() < curr)
        {
            // this top value is our next smaller value
            arr[i] = st.top();
        }

        // condition 3 :
        else
        {
            while (!st.empty() && st.top() >= curr)
            {
                st.pop();
            }

            if (st.empty())
            {
                arr[i] = -1;
            }
            else
            {
                // here value is smaller than current value(which is next smaller )
                arr[i] = st.top();
            }
        }
        st.push(curr);
    }
    return arr;
}

// function to print array
void printArray(vector<int> arr)
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
    vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    printArray(arr);
    vector<int> ans = nextSmaller_Optimised(arr);
    printArray(ans);
    return 0;
}
/*
article Link :

*/