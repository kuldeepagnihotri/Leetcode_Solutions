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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return(p==q);
// do any traversal pre or post , find traversal for the both trees and if the travelsal is same then they are identical
        return (p->val == q->val) &&
         isSameTree(p->left,q->left) &&
         isSameTree(p->right,q->right);
        
    }
};