# Create a Binary tree and show them as levelOrder, PreOrder and InOrder traversal:


## Make  this tree:

![image](https://github.com/NIBRAS-N/Competitive-Programming-From-Scratch/assets/83491751/f08faa11-2136-4cd2-8442-530d07de81c0)

```C++


// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;
    
    Node(int d ){
        this -> val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout<<"enter data for the node: "<<endl;
    cin>>data;
    
    root = new Node(data);
    if(data == -1) return NULL;
    
    cout<<"Enter data to add left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to add right of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}
void leverOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);//after every level a NULL value will be there
    
    while(!q.empty()){
        Node* temp = q.front();
        
        q.pop();
        if(temp == NULL){// previuos level traversal completed
            cout<<endl;
            if(!q.empty()){// some child remains,, we need to print them
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node* root){// Left root right
    if(root == NULL) return;
    
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){/// Root left right
      if(root == NULL) return;
    
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){// left right root
     if(root == NULL) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}
int main() {
    Node* root = NULL;
    root = buildTree(root); 
    
    cout<<"Print the lavel order traversal"<<endl;
    
    leverOrderTraversal(root);
    
    cout<<endl<<"Print the inOrder traversal"<<endl;
    inOrder(root);
    cout<<endl<<"Print the preOrder traversal"<<endl;
    preOrder(root);
    cout<<endl<<"Print the postOrder traversal"<<endl;
    postOrder(root);
    return 0;
}
```
## Input

 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
 
## Output

![image](https://github.com/NIBRAS-N/Competitive-Programming-From-Scratch/assets/83491751/60b5d3b0-aab7-45c8-bd40-10105e9d88b6)



