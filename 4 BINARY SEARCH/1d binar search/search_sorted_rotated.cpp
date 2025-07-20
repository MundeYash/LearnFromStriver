#include<iostream>
#include<vector>
using namespace std ; 
// search in the sorted and rotated array -1 
int search_sorted_rotatedArray(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    // applying the binary search : time : O(log n )
    int s =0 ,e =n-1 ; 
    while (s<=e ){
        int mid = (s + (e-s)/2) ; 
        if (arr[mid] ==  k ){
            return mid ; 
        }

        // eleminating the search space 

        // searching in the left part 
     if (arr[s]<= arr[mid]){
         // left part is sorted and answer will be there and check if k is present in the range 
          if (arr[s]<= k and k<= arr[mid]){
              // k is present 
              e = mid - 1; 
          }
          else {
              s = mid + 1; 
          }
     }

        // searching in the right part 
        else {
       if (arr[mid]<= k and k<= arr[e]){
              // k is present 
             s = mid + 1; 
          }
          else {
             
                e = mid - 1; 
          }
          
         }
         // left part is sorted and answer will be there and check if k is present in the range 
        
     
     
    }
     return -1 ;
}

int main (){
    return 0 ;
}