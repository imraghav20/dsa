#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    string key;
    Node* left, *right;
};

int evalTreeRecur(Node* root){
    if(!root->left and !root->right){
        return stoi(root->key);
    }
    int left = evalTreeRecur(root->left);
    int right = evalTreeRecur(root->right);
    if(root->key == "+"){
        return left+right;
    }
    else if(root->key == "-"){
        return left-right;
    }
    else if(root->key == "/"){
        return left/right;
    }
    else if(root->key == "*"){
        return left*right;
    }
}