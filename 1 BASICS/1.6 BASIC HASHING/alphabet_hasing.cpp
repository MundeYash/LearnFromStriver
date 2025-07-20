#include<bits/stdc++.h>
using namespace std  ; 

// Brute Force : Method for finding the count of a character in the given string 
int countCharacter (string s , char ch  ){
    int count =0 ; 
int n = s.size() ; 
for (int i=0 ;i<n ;i++){
    if (s[i] == ch ){
         count ++ ;
    }
}
return count ;

}


//Function for implementing Basic hashing for the alphabets 
int AphlaCount(string s , char ch  ){
    // Condition : all the character should be either in lowercase / uppercase format 
    // concept Used : mapping of character to a integer value which acts a index 

    int n = s.size() ; 
   int hashh[21000] ={0};

    for (int i=0 ;i<n;i++){
        // int index = s[i]-'a' ;
        // hashh[index]++ ;
        hashh[s[i]]++ ;
    }
    
    // return hashh[ch-'a'] ;
    return hashh[ch] ;

}
int main (){
    string s ; 
    cin>> s ; 
    char ch ; 
    cout<<"Enter the character "; 
    cin>> ch ; 


    cout<<"The count of "<<ch<<" is : "<<countCharacter(s , ch ) <<endl;
    cout<<"The count of "<<ch<<" is : "<<AphlaCount(s , ch ) <<endl;
    return 0 ; 
}