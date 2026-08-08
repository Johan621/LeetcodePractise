/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int balancedtree(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = balancedtree(root->left);
        if(left == -1) return -1;
        int right = balancedtree(root->right);
        if(right == -1) return -1;
        if(abs(left-right)>1){
            return -1;
        }
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int ans = balancedtree(root);
        return (ans==-1)?false:true;
    }
};