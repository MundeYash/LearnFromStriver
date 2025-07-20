#include<bits/stdc++.h>
using namespace std ; 

// approach -1 (Sort the elements )
vector<int> sort012_brute(vector<int>arr ){
    // concept : sorting , time : O(n log n ) , space : O(1)
    int n = arr.size() ; 
    sort(arr.begin(), arr.end() ) ; 
    return arr; 
    
}
// Approach -2 (count and store )
    vector<int> sort012_better(vector<int>& nums) {
        //concept  : Count the occurnce of 0,1,2 and place them  , Time :O(n) , space : O(1)
        int n =nums.size() ;

        int c0 , c1 , c2 ; 
        c0 = c1 = c2 = 0 ; 

        // count stored 
        for (int i=0 ;i<n ;i++){
            if (nums[i] ==0){
                c0++ ;
            }
            else if (nums[i] ==1){
                c1++ ;
            }
           else {
                c2++ ;
            }
        }
        // placing 
        for (int i=0 ;i<c0;i++){//0 placed 
            nums[i] =0 ;
        }
        for (int i=c0 ;i<c0+c1 ;i++){//1 placed 
            nums[i] =1 ;
        }
        for (int i=c0+c1 ;i<n;i++){//2 placed 
            nums[i] =2 ;
        }

         return nums ;
        
    }


// Approach 3 : region based making , duetchse national flag algorithm 
vector<int> sort012_Optimised(vector<int>arr ){
    // concept : region defining for 0 , 1 ,2 + two pointer , Time : O(n) , space : O(1)
    /*
        sorted 0 - ( 0 to low -1 ) 
        sorted 1 - ( low to mid -1 )
        unsorted - ( mid to high )
        sorted 2 - ( high +1 to n-1 )

    */

    int n = arr.size() ;
    int low = 0 , mid = 0 , high = n-1 ;
    while(mid<=high ){
        if (arr[mid] ==0){
            // means 0 is currently in wrong region , 
            swap(arr[low] , arr[mid]) ;
            low++ ;
            mid++ ;
        }
        else if (arr[mid] ==1){
            // means 1 is in right position
            mid++ ;
        }
        else {
            // means 2 is in wrong region
            swap(arr[mid] , arr[high]) ;
            high-- ;
        }
    }
}

void print(vector<int>arr ){
    int n = arr.size() ; 
    for (int i=0 ;i<n ;i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main (){
    vector<int>arr = {0,1,1,0,2,1,0,1,2,2,2,1,2,0} ; 
    print(arr);
     cout<<"Brute force Approach " ;
    vector<int> ans = sort012_brute(arr) ;
    print(ans);
   
    cout<<"Better Approach ";
    vector<int> ans1 = sort012_better(arr) ;
        print(ans);
        
    cout<<"Optimised Approach ";
    vector<int> ans2 = sort012_Optimised(arr) ;
        print(ans);
            
    return 0 ;
}