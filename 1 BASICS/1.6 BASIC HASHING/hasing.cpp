#include <iostream>
using namespace std;
// Basic Hashing in the C++

// BRUTE FORCE APPROACH FOR HASHING / COUNT OF EACH ELEMENTS
int numCount(int a[], int n, int num)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    int a[] = {2, 3, 5, 1, 2, 2, 21, 1, 13, 3, 5, 5, 100, 1000};
    int n = sizeof(a) / sizeof(int);
    int num;
    cout << "Enter number " << endl;
    cin >> num;

    cout << "The frequency of " << num << " is : " << numCount(a, n, num) << endl;

    return 0;
}