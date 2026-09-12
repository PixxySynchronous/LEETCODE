// 958. Check Completeness of a Binary Tree
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
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
    int countNodes (TreeNode* root){
        if (root == NULL)
            return 0; 
        int ans = 1 + countNodes (root -> left) + countNodes (root -> right); 
        return ans; 
    }
    bool isCBT (TreeNode* root, int index, int count){
        if (root == NULL)
            return true; 
        //first we check the current node. 
        if (index >= count)
            return false; //we know it isnt a CBT
        //else current node is CBT for now, but we need to check 2 more things
        int leftIndex = 2*index + 1; 
        int rightIndex = 2*index + 2; 
        bool left = isCBT(root -> left, leftIndex, count);
        bool right = isCBT (root -> right, rightIndex, count); 
        return left && right; 
    }
    bool isCompleteTree(TreeNode* root) {
        /* to check if a tree is complete, we first need to count the total number of nodes in the tree. A complete tree will only have array indices less than the node count. If any index is greater than the node count, it means we have skipped a left node somewhere, indicating that it is not a CBT. 
        */
        int count = countNodes (root); 
        int index = 0; //root index 
        return isCBT(root, index, count); 

    }
}; 
//since we traverse the entire tree twice, the time complexity is O(n). The space complexity is O(h) for the recursion stack, where h is the height of the tree.