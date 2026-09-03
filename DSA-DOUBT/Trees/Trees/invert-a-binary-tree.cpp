// Invert Binary Tree
// Easy
// Topics
// Company Tags
// Hints
// You are given the root of a binary tree root. Invert the binary tree and return its root.

// Example 1:



// Input: root = [1,2,3,4,5,6,7]

// Output: [1,3,2,7,6,5,4]

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root; 
        TreeNode* temp = root -> left; 
        root -> left = root -> right; 
        root -> right = temp; 
        invertTree ( root -> left); 
        invertTree ( root -> right); 
        return root; 
        
    }
};
//TC is O(n) where n is the number of nodes in the tree. As the fuunction
//does constant work for each node and visits each node once.
//SC is O(h) where h is the height of the tree.