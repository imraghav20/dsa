/*

Given a binary tree, flatten it to a linked list in-place.

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
void f(TreeNode *root)
{
if(root==NULL or (root->left==NULL and root->right==NULL))
{
return;
}
if(root->left!=NULL)
{
f(root->left);
TreeNode *temp = root->right;
root->right = root->left;
root->left = nullptr;

    TreeNode *t = root->right;
    while(t->right!=NULL)
    {
        t = t->right;
    }
    t->right = temp;
    
}
f(root->right);
}
TreeNode* Solution::flatten(TreeNode* A) {
f(A);
return A;
}
