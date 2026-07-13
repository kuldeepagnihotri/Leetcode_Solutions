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
    int maxPath(TreeNode* root, int & maxi){// to find height pattern is applied here 
        if(root==NULL) return 0;
        int lsum=max(0,maxPath(root->left,maxi));
        int rsum=max(0,maxPath(root->right,maxi));
        maxi=max(maxi,lsum + rsum+ root->val);//backtracking logic
        return root->val+max(lsum,rsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPath(root,maxi);
        return maxi;

        
    }
};