#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define j 0
#define SPACE 5
struct node              // Structure defined for each node
{
    int val;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
struct node* createNode(int data){       //function which initializes a new node
    int nodeSize = sizeof(struct node);
    struct node* newNode = (struct node*)malloc(nodeSize);
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insertNode(struct node* current, int data)    //inserts a node in BST
{
    if (current == NULL)     // if the current reaches NULL, data is to be inserted here
        return createNode(data);
    if (current->val < data)
        current->right = insertNode(current->right, data); 
    else if (current->val > data)
        current->left  = insertNode(current->left, data); 
 
    return current;
}
void inOrderTraversal(struct node* current){  //recursive code to print in-order
    if(current == NULL)  // reaches end of any leaf and can’t go any deeper in tree
       return;
    inOrderTraversal(current->left); 
    cout<<" "<<current->val<<" "<<++j<<endl;
    inOrderTraversal(current->right);
    
}
struct node* minval_rightsubtree(struct node* parent)
{
    struct node* temp=parent;
    while(temp!=NULL && temp->left!=NULL)    
    {
        temp=temp->left;
    }
    return temp; 
}
struct node* delete_node(struct node* root,int k)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(k<root->val)
    {
        root->left=delete_node(root->left,k);
    }
    else if(k>root->val)
    {
        root->right=delete_node(root->right,k);
    }
    else
    {
        if(root->left ==NULL && root->right ==NULL)
        {
            return NULL;
        }
        else if(root->left ==NULL)
        {
            struct node*temp =root->right;
            free(root);
            return temp;
        }
        else if(root->right ==NULL)
        {
            struct node*temp =root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node*temp=minval_rightsubtree(root->right);
            root->val=temp->val;
            root->right=delete_node(root->right,temp->val);
        }
    }
    return root;
}
bool bs(struct node* root,int k)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(k<root->val)
    {
        return bs(root->left,k);
    }
    else if(k>root->val)
    {
        return bs(root->right,k);
    }
    else if(root->val ==k)
    {
        return true;

    }
    else
    {
        return false;
    }
}

void print2D(struct node* r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> val << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
}
int main(){
    root = insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 7);
    print2D(root,5);
    inOrderTraversal(root);
    return 0;
}