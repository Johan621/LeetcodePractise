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
bool check(TreeNode* root,long long min_range,long long max_range){
    if(root == nullptr) return true;
    if(root->val <= min_range || root->val >= max_range){
        return false;
    }
    bool left = check(root->left,min_range,root->val);
    bool right = check(root->right,root->val,max_range);
    return (left == true && right == true)?true:false;
}
public:
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};