// 101. Symmetric Tree
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:


// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:
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
    bool check (TreeNode* right, TreeNode* left){
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false; 
        if (left -> val != right -> val)
            return false; 
        
        return check (left->left,right->right) && check (right ->left, left -> right); \
        // as we need to check symmetry^^ pay attention to the calls; 
        
    }
    bool isSymmetric(TreeNode* root) {
        return check (root -> left, root -> right); 
    }
};