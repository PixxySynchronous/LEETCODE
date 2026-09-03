Subtree of Another Tree
Easy
Topics
Company Tags
Hints
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


Example 1:



Input: root = [1,2,3,4,5], subRoot = [2,4,5]

Output: true
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
    bool sameTree ( TreeNode* root, TreeNode* root2){
        if (root == NULL && root2 == NULL) 
            return true; 
        if (root == NULL || root2 == NULL) 
            return false; //if either of the roots are NULL, structure is not the same. 
        if ( root -> val == root2 -> val){
            return sameTree( root -> left, root2 -> left) && sameTree (root -> right, root2 -> right); 
        }
        else return false; 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // We first need to find the starting of the subRoot in our main tree, so we check the root value and the subRoot value. 
        if (root == NULL && subRoot == NULL) //both null, null trees are considered subset of each other. 
            return true; 
        if (root == NULL || subRoot == NULL) //if one is null and other isnt, return false as subset cant be present. 
            return false; 
        bool check = false; 
        if (root -> val == subRoot -> val) //if value is same, call a function which checks if the trees are same or not from that node. 
            check = sameTree (root, subRoot); 
        if (check)
            return true; //if trees are same, return true as we have found the subroot in the root
        else{ //else search the left subtree and the right subtree. 
            return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot); //if either return true, we get true, else false. 
        }
            

    }
};
// TC: o(N) and SC: o(H)