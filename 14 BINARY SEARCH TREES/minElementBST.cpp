// date = 31 March -2024 sunday 

#include<bits/stdc++.h>
using namespace std; 

// Problem : find the minimum / maximum element in the binary search tree 

class Node{
    public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    // default constructor 

    Node(int d ){
        this ->data = d ; 
        this->left  = NULL ; 
        this->right = NULL;
    }

};

// function for creating a tree in the  level order traversal format  

 void createTree(Node* &root ){

    int data ; 
    cin>> data ; 

    if (data==-1 ){
        // means null node 
        root= NULL ; 
        return ; 
    }

    // concept : using Queue 
    else {
        queue<Node*> q; 
        root = new Node(data);
        q.push(root);

       
       while (!q.empty()){

        Node* frontNode = q.front() ; 
        q.pop();


        cout<<"Enter the data for the leftchild of "<<frontNode->data <<endl;
         // left child 
        int leftData ; 
        cin>> leftData ; 
        if (leftData!=-1 ){
            frontNode->left = new Node (leftData);
            q.push( frontNode->left);
        }

       cout<<"Enter the data for the leftchild of "<<frontNode->data <<endl;
        int rightData ; 
        cin>> rightData    ; 
        
        if (rightData!=-1 ){
            frontNode->right = new Node (rightData);
            q.push( frontNode->right);
        }


       }
    
    }
   
    return ;
}

// function for finding the minimum element in the bst 

/*
    Brute Force Approach : find the inorder traversal , store it and find the minimum element in it 
    time ; O(n) , space : O(n)
*/
int minElement (Node* root ){
    //Optimised Approach : concept :Iterative Method 
    // time : O(n) , space : O(1)

    int ans = root->data; 

    while (root){

        if (root->data<ans) ans = root->data ;

        if (root->left){
            root = root->left;
        }
        else{
            break ;
        }
    }
    return ans ;
}



// function for finding the maximum element in the bst 

/*
    Brute Force Approach : find the inorder traversal , store it and find the maximum element in it 
    time ; O(n) , space : O(n)
*/
int maxElement (Node* root ){
    //Optimised Approach : concept :Iterative Method 
    // time : O(n) , space : O(1)

    int ans = root->data; 

    while (root){

        if (root->data>ans) ans = root->data ;

        if (root->right){
            root = root->right;
        }
        else{
           root = root->left;
        }
    }
    return ans ;
}
int main (){
    Node* root = NULL ;
    createTree(root); 

    cout<<"The maximum element in the bst is : "<<minElement(root)<<endl;
    cout<<"The maximum element in the bst is : "<<maxElement(root)<<endl;

    return 0 ;
}
// 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1