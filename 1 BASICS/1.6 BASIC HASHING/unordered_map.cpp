#include<iostream>
#include<map>// header file for the ordered map 
#include<unordered_map> // header file for the unordered_map 
#include<string>// header file for the string 
using namespace std ; 

// Key- Value pair in the map hasing concept 
int main(){
    int a[] = {1,2,3,5,3,13,1,2,2,1,33,100} ; 
    int n = sizeof (a) /sizeof (int) ; 
    int num =5 ; 
    string s = "goodmoring" ;
    int m = s.size() ;
    // cin>> num ; 
    unordered_map<int , int > hashh ; 
    map<char , int > alpha ; 

    // Pre-computation work 
    for (int i=0 ;i<n ;i++){
        hashh[a[i]] ++;
    }

    // iterating over the map 
    for (auto it: hashh){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    // fetching the data 
    cout<<"The count of "<<num<<" is : "<<hashh[num]<<endl;



    // work for the character key and value map 

    for (int i=0 ;i<m ;i++){
        alpha[s[i]]++ ;
    }
    for (auto it: alpha){
        cout<<it.first<<"->"<<it.second<<endl;

    }


    return 0 ;
}