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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;//all levels of the queue will be inserted in vector
        if(root==NULL) 
        return result;

        queue<TreeNode*> nQueue;
        nQueue.push(root);
        //push the root node

        bool leftToright=true;
        while(!nQueue.empty()){//all elements will be pushed here
        int size= nQueue.size();
        vector<int> row(size);

        for(int i =0;i<size;i++){
            TreeNode* node = nQueue.front();
            nQueue.pop();//deleting the levels from the queue and inserting in the vector

             // now to find position
             int index=(leftToright) ? i : (size - i - 1);
             row[index] = node->val;
             if(node->left)
             nQueue.push(node->left);
             if(node->right)
             nQueue.push(node->right);

             
        }
    
             leftToright = !leftToright;
             result.push_back(row);
        }
            return result;
        
    }
};