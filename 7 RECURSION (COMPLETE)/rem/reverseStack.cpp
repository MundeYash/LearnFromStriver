#include<bits/stdc++.h>
using namespace std ; 
//Question Name : Reverse Stack : given a stack and we need to reverse it 

stack<int> reverseStackBrute (stack<int> st ){
    // concept : use another stack and return it  ,time : O(n) , space : O(n -> due to stack )
    stack<int> temp ; 
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    return temp ; 
}

void solve(stack<int> &st){
    // base case 
    if (st.empty()){
        return ; 
    }
    // store the top value and place it in the stack at later time 
    int value = st.top() ; 
    st.pop() ; 
    solve(st ) ; 
    
}
stack<int> reverseStack_Optimised(stack<int> st ){
    // concept : recursion , time : O(n) , space: O(n -> recursive stack space , not any extra space ) ; 
    if(st.size() == 1){
        return st ; 
    }

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

void printStack(stack<int> st ){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();   
    }
    cout<<endl;
}
int main (){
    // create array and print its value 
vector<int> arr = {32, 1, 3, 1, 32, 3, 11, 10, 100};
    printArray(arr);
    stack<int> st ; 
    for(int i = 0 ; i < arr.size() ; i++){
        st.push(arr[i]);
    }
    printStack(st);
    stack<int> ans1 = reverseStackBrute(st) ; 
    printStack(ans1) ; 



    return 0 ;
}
/*
article Link : 

*/