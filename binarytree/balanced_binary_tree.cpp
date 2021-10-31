class Solution {
public:
    
    int checkHeight(TreeNode* root, bool &result){
        if(!root)return 0;
        if(!result) 0;
        
        int left = checkHeight(root->left, result);
        
        if(!result)return 0; // if left subtree is unbalanced return, check in right subtree is not necessary
        
        int right = checkHeight(root->right, result);
        
        int diff = abs(left - right);
        if(diff>1){
            result = false;
        }
        
        return max(left, right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
       if(!root)return true;
        
        bool result = true;
        checkHeight(root, result);
        return result;
    }
};
