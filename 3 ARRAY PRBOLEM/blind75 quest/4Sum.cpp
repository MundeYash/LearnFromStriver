#include <bits/stdc++.h>
using namespace std;
// Question Name : Given an array we need to find the quadruples (mean four values that sum up to target value ) and target value integer , We need to return all the possible quadruples

vector<vector<int>> FourSum_brute(vector<int> arr, int target)
{
    // concept : 4 loops ,set , comparion 
    // time : (n^4) , space : O(n)
    // for removing duplicate value push it into the set
    set<vector<int>> s;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == target)
                    {
                        vector<int> temp{arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> res(s.begin(), s.end());
    return res;
}

vector<vector<int>> FourSum_Better(vector<int>arr , int target ){
    int n = arr.size();

    // concept : 3 loops , set , comparion, Hahsing approach 
    // time : O(n^3) , space : O(n)
    set<vector<int>> s;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            set<int>mp ; 
           for (int k= j+1;k<n ;k++ ){
            
            int more = (target- (arr[i]+ arr[j] + arr[k])) ;
           
            if (mp.find(more) != mp.end()){
                vector<int> temp{arr[i], arr[j], arr[k], more};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            mp.insert(arr[k]);
            
           }
        }
    }
    vector<vector<int>> res(s.begin(), s.end());
    return res ;
}

vector<vector<int>> FourSome_Optimised(vector<int>arr , int target ){
    // concept : Two pointer sorting and pair finding 
    sort(arr.begin(),arr.end()) ;
    int n = arr.size();
    vector<vector<int>> res ;
    for (int i = 0; i < n; i++)
    {
        // avoid the duplicates while moving i:
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n; j++)
        {
            // avoid the duplicates while moving i:
        if (j > i+1 && arr[j] == arr[j - 1]) continue;
            int left =j+1 ;
            int right =n-1 ; 
            while (left<right){
                int sum = arr[i] + arr[j] + arr[left] + arr[right] ;
                if (sum == target){
                    res.push_back({arr[i], arr[j], arr[left], arr[right]});
                    left++ ;
                    right-- ;


                      //skip the duplicates:for (right and left poitner )
                    while (left < right  && arr[left] == arr[left - 1]) left++;
                    while (left < right  && arr[right] == arr[right + 1]) right--;
                }
                else if (sum < target){
                    left++ ;
                }
                else {
                    right-- ;
                }
            }
        }
      
    }
    return res ;
}
// function for printing all the four pairs
void printPairs(vector<vector<int>> arr)
{
    for (auto i : arr)
    {
        cout << "(" << i[0] << "," << i[1] << "," << i[2] << "," << i[3] << ")  ,";
    }
    cout << endl;
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
    int target = 47;

    cout << "Brute force Approach ";
    vector<vector<int>> ans1 = FourSum_brute(arr, target);
    printPairs(ans1);
    cout << "Better Approach ";
    vector<vector<int>> ans2 = FourSum_Better(arr, target);
    printPairs(ans2);

    cout << "Optimised Approach ";
    vector<vector<int>> ans3 = FourSome_Optimised(arr, target);
    printPairs(ans3);


    return 0;
}
/*
article Link :https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/

https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1



*/