#include<bits/stdc++.h>
using namespace std ; 
// finding the Intersection of two sorted arrays : Given both the array are sorted 



// Approach 2: optimal approach 
vector<int> optimisedArrayIntersection (vector<int> a , vector<int > b){
     int n = a.size  () ; 
    int m = b.size() ; 
    // concept : Two Pointers approach , time : O(N+M)  , space : O(min(n,m))
   vector<int> ans ; 
    int i=0 , j=0 ; 
    while (i<n and j<m ){
        if (a[i]<b[j]){
            i++ ;
        }
        else if (a[i]== b[j]){
            ans.push_back(a[i] ) ; 
            i++; 
            j++ ;
        }
        else {
            j++ ;
        }
    }
     return ans ;
}


vector<int> bruteForce_arrayIntersection (vector<int> a , vector<int > b ){
    int n = a.size  () ; 
    int m = b.size() ; 
   vector<bool > visited (m,0) ; 
   vector<int> ans ; 
    // time O(n*m) , space :  O(N) linear 
    for (int i=0 ;i<n ;i++){
        for (int j=0;j<m ;j++){
            if (a[i] ==  b[j ] and visited[j] == false ){
                ans.push_back(a[i]) ; 

                visited[j]= true ;
                break ; // means finded the corresponding element 

            }
            if (b[j]> a[i]) break ;

        }
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
    vector<int> a = {1,2,2,3,3,4,5,6}; 
    vector<int> b = {2,3,3,5,6,6,7}  ; 
    vector<int> ans = bruteForce_arrayIntersection(a,b) ;
    // vector<int> ans = optimisedArrayIntersection(a,b) ;
    print(ans);
    return 0 ;
}