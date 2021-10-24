/*

Given two Binary Trees A and B, you need to merge them in a single binary tree.
The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.
Otherwise, the non-null node will be used as the node of new tree.

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *mergetree(TreeNode *a, TreeNode *b){
    //if(a==NULL and b==NULL) return NULL;
    if(a!=NULL and b!=NULL)
    {
        TreeNode *root = new TreeNode(a->val + b->val);
        root->left = mergetree(a->left,b->left);
        root->right = mergetree(a->right, b->right);
        return root;
    }
    else{
        if(a==NULL) return b;
        return a;
    }
}
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    
    if(A==NULL) return B;
    if(B==NULL) return A;
    return mergetree(A,B);
}
