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
    void sumofsubtree(TreeNode* root,int &sum,int &cnt){
        if(root == nullptr){
            return;
        }
        sum += root->val;
        cnt++;
        sumofsubtree(root->left,sum,cnt);
        sumofsubtree(root->right,sum,cnt);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        int sum = 0,cnt = 0,rescnt = 0;
        sumofsubtree(root,sum,cnt);
        
        if(sum/cnt == root->val) rescnt++;

        rescnt += averageOfSubtree(root->left);
        rescnt += averageOfSubtree(root->right);

        return rescnt;
    }
};