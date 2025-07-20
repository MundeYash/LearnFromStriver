#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Given an array of integer and we need to find the next greater element in the array.
// Next Greater Element is the first greater element that appear to right side of the array 

//Approach 2: Optimised Approach 
vector<int>nextGreater_Optimised(vector<int>arr ){
    // concept : stack based approach , time :O(n) , space :O(n)
    int n = arr.size();
    stack<int>st;
    // right to left traversal because of (finding next value )
    for(int i=n-1 ;i>=0 ;i-- ){
        int curr = arr[i] ;
        // conditiion 1 : 
        if (st.empty()){
            arr[i] = -1;
        }

        // condition 2 : 
        else if (!st.empty() && st.top()>curr ){
             // this top value is our next greater value 
            arr[i] = st.top();
        }


        // condition 3 : 
        else{
            // pop until we get the next greater value 
            while (!st.empty() && st.top()<=curr){
                st.pop();
            }
            if (st.empty()){
                arr[i] = -1;
            }
            else{
                // here value is greater than current value(which is next greater )
                arr[i] = st.top();
            }
        }

        st.push(curr );
    }
    return arr ;
}
//Approach 1 : Brute force Approach 

int findJustGreaterRight(int index , vector<int>arr , int n ){
    for (int i = index ; i<n ;i++){
        if (arr[i]>arr[index-1]){
            return arr[i];
        }
    }
    return -1;
}
vector<int>nextGreater_Brute(vector<int>arr ){
 
    // concept : Two loops and finding next Greater , time : O(n^2) , space : O(1) 
    int n = arr.size();
       vector<int> ans (n,-1);
    for (int i= 0 ;i<n ;i++ ){
        int value = findJustGreaterRight(i+1 , arr , n );
        ans[i] =value ;
    }

    return ans;
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
vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    printArray(arr);

    cout<<"Brute force Approach ";
    vector<int>ans  = nextGreater_Brute(arr) ; 
    printArray(ans);

    cout<<"Optimised Approach ";
    vector<int>ans2  = nextGreater_Optimised(arr) ; 
    printArray(ans2);
    return 0 ;
}
/*
article Link : 

*/