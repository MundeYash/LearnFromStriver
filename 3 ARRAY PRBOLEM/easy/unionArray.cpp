#include<bits/stdc++.h>
using namespace std ; 

//UNION OF TWO SORTED ARRAYS 

    // brute force approach : finding using the set / hashmap 
    // time : O(n1 log n  + n2 log n ) , space : O(n1 + n2 )

vector<int> optimisedUnionArray (vector<int> a , vector<int> b ){

    // Optimised Approach :  concept : Two pointers , time : O(n + m )   , space : O(n+ m )
     int n = a.size() ; 
     int m = b.size() ; 
     vector<int> ans ; 
     // step 1 : take the minimum that is not present in ans array and add it  
     int i =0 , j =0 ; 
     while (i<n and j<m ){
        if (a[i]<= b[j]){

            // means we have to add the smaller value 
            if (ans.size() == 0 || ans.back() != a[i]){
                ans.push_back(a[i] ) ;
               
            }
             i++ ; // we will be increase the pointer no matter of value 

        }

        else{
            // b[j ] have the samller value 
            if (ans.size() ==0 || ans.back() != b[j]){
                ans.push_back(b[j]) ;
            }
            j++ ;// increase the iterator irrespective of the value 
        }
     }


     // case 2 : some of the elements still left in one of the array 
     while (i<n ) // some elementts left the a[i] array 
     {
        if (ans.back() != a[i]){
            ans.push_back(a[i]);
        }
        i++ ;
     }


   while (i<n ) // some elements left in the b[j]  array 
     {
        if (ans.back() != a[i]){
            ans.push_back(a[i]);
        }
        i++ ;
     }

     return ans ;
}

// function for printing the array 
void print (vector<int> a ){
    for (int i=0 ;i<a.size() ; i++){
        cout<<a[i]<<" ";

    }
    cout<<endl;

}
int main (){
    vector<int> a= {2, 2, 3, 4, 5} ;
    vector<int> b={1, 1, 2, 3, 4};
    vector<int> ans = optimisedUnionArray(a,b) ; 
    print(ans) ;


}