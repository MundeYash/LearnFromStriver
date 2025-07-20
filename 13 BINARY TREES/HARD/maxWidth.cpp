#include<bits/stdc++.h> 
using namespace std ; 

//Problem : finding the maximum width in the binary tree , 
// MAx Width :- maximum distance bewteen leftmost node to rightmost node at a level 
//Time : O(n-> no of nodes ) , Space : O(n->no of nodes )

class node{
    public: 
    int data ; 
    node* left ; 
    node* right ; 

    node(int d ){
        data = d; 
        left = right = NULL ;
    }

};

node*  createTree(){
    // preOrder INput :8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    int data ; 
    cin>> data ; 

    node* root = new node(data) ;
    root->left = createTree() ;
    root->right = createTree() ;
    return root ;

}


// function for finding maximum width of binary tree
int maxWidth (node* root ){
    // base case 
    if (!root ){
        return 0 ;
    }
    int ans =0 ; 

    //Concept: Level Order traveral + forumla = (rightMOstNOdeIndex- leftmostNOdeINdex   + 1 )
    queue<pair<node*  , int >> q ;
    q.push({root , 0 }) ;


    while (!q.empty()){
        int size = q.size() ; 
        int curMin= q.front().second ; // for handling inter overflow case in formula 
        int leftMost , rightMost ; 


        for (int i=0 ;i<size ;i++){
          long long   int curI = q.front().second - curMin ; // subtract to prvent the integer overflow 

            // finding front node 
            node* frontNode = q.front().first;
            q.pop() ;

            if (i==0 ){
                leftMost = curI ;
            }
            if (i==size-1){
                rightMost = curI ;
            }

            // work for the child nodes 

            if (frontNode->left){//left->(2*i +1 ) or 2*(i- curMIn)+1 
            q.push({frontNode->left , (2*curI)+1 });


            }

            if (frontNode->right){//left->(2*i +1 ) or 2*(i- curMIn)+1 
            q.push({frontNode->right , (2*curI)+ 2 });


            }


        }

        ans  = max(ans,(rightMost - leftMost + 1)) ;
    }
    return ans ;


    
}
int main (){
    node* root = createTree();


    cout<<maxWidth(root) <<endl;
    return 0 ;
}