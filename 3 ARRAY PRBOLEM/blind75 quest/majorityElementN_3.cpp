#include<bits/stdc++.h>
using namespace std ; 
//Question Name : 
vector<int> majorityElementsNBy3_Brute(vector<int>arr ,int n ){
    vector<int> ans  ; 

    // brute force approach: concept : sorting , time complexity : O(n log n), space : O(1) ; 

        //edge case 
    if (n==0 || n==1 ) return ans ;
    int count =1 ; // for first element at 0th index 
    // step 1 : sort the array 
    sort(arr.begin() , arr.end() );
    for (int i=1 ;i<n ;i++ ){
        if (arr[i] == arr[i-1]){
             count ++ ;
        }
        else{
            // different element is finded and check the count for previous element
            if (count>(n/3)){
                ans.push_back(arr[i-1]);
            }
            count = 1 ;
        }
    }

    // check for the last index 
    if (count>(n/3)){
                ans.push_back(arr[n-1]);
        }
    return ans ;
}


vector<int> majorityElementsNBy3_Better(vector<int> arr , int n ){
    // concept : hashing , time : O(n) , space : O(n)
    vector<int> ans ;
    unordered_map<int , int> map ;
    for (int i=0 ; i<n ; i++){
        map[arr[i]]++;
    }
    for (auto it : map){
        if (it.second > (n/3)){
            ans.push_back(it.first);
        }
        }
    return ans ;

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

int main (){
    // create array and print its value 
vector<int> arr = {2,2,1,1,1,2,2};
    printArray(arr);
    cout<<"Majority Elements are : \n";


    cout<<"Brute force Approach " ;
    vector<int> ans = majorityElementsNBy3_Brute(arr , arr.size());
    printArray(ans);
    cout<<"Better Approach ";
    vector<int> ans1 = majorityElementsNBy3_Better(arr , arr.size());
    printArray(ans1);

    
    cout<<"Optimised Approach ";
    
    return 0 ;
}
/*
article Link : 

*/