#include <bits/stdc++.h>
using namespace std;
// Question Name : Rotation of arary
/*
VAiration 1 : Clockwise or Anticlockwise rotation of array by one place

Variation 2 : Rotate the array by d elements
*/
// Brute force Approach :
vector<int> cyclicRotateOnePlace(vector<int> arr, int n)
{
    // concept : store end element and shift element to right from that end
    //  time : O(n) , space : O(1)

    // step 1: store the last end element whose side rotation is done
    

    int endElement = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = endElement;
    return arr;
}

//************************************************************************* */

vector<int> kCyclicRotate_better(vector<int> arr, int k)
{ // right  direction rotation
    // concept : store somewhere and return
    // time : O(n) , space : O(n )
    int n = arr.size();
    vector<int> temp;
    k = k % n;

    // step 1: store last k elements somewhere
    for (int i = n - k; i < n; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    return arr;
}

void rotateArray(vector<int> &arr, int s, int e)
{
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

vector<int> kCyclicRotate_Optimised(vector<int> arr, int n, int k)
{ // rotation of elements towards right side

    // important edge cases
    if (n == 0)
        return arr;
    k = k % n;

    if (k > n)
        return arr;

    // step1 : rotate the last k elements
    rotateArray(arr, n - k, n - 1);

    // step 2: rotate the first half of (n-k) elements
    rotateArray(arr, 0, n - k - 1);

    // step 3: rotate the whole array
    rotateArray(arr, 0, n - 1);
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArray(arr);
    cout << "Brute force Approach , After cyclic rotate 1 position ";
    vector<int> arr2 = cyclicRotateOnePlace(arr, arr.size());
    printArray(arr2);

    int k = 43;
    cout << "Better Approach " << "After cylic rotation " << k << " positions ";
    vector<int> ansBetter = kCyclicRotate_better(arr, k);
    printArray(ansBetter);
    cout << "Optimised Approach ";
    vector<int> ansOptimised = kCyclicRotate_Optimised(arr, arr.size(), k);
    printArray(ansOptimised);

    return 0;
}
/*
article Link :https://takeuforward.org/data-structure/rotate-array-by-k-elements/

*/