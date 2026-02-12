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
    int maxDia;
    int dfs(TreeNode*node){
        if(node == nullptr)//base case
        return 0;
//recursively find the longest path both left and right
        int leftPath = dfs(node->left);
        int rightPath = dfs(node->right);
//update the diameter 
        maxDia=std :: max(maxDia, leftPath+rightPath);
//return the longest one between the left and right +1
        return std :: max(leftPath,rightPath) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDia = 0;
        dfs(root);//first call of dfs
        return maxDia;

        
    }
};