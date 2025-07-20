#include <bits/stdc++.h>
using namespace std;
// Finding the count of a number in the array
//  Brute force method using Two loops
int countNumber(vector<int> &a, int number)
{
    int count = 0, n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == number)
        {
            count++;
        }
    }
    return count;
}

// finding using the hash array
int main()
{
    vector<int> a = {2, 1, 3, 1, 3, 1, 2, 2, 2, 4, 4, 3, 4};
    int n = a.size();

    int hash[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    // printing the numbers
    int i ; 
    cin>> i;
cout<<"Count is: "<<hash[i]<<endl; // hashing method 
    cout << countNumber(a, i) << endl; // brute force count method 
    return 0;
}