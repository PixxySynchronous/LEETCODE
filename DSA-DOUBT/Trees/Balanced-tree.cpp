Balanced Tree Check
Solved
Difficulty: EasyAccuracy: 43.15%Submissions: 370K+Points: 2Average Time: 20m
Given the root of a binary tree, determine if it is height-balanced or not.

Note: A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

Examples:

Input: root = [10, 20, 30, 40, 60]

Output: true 
Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.
/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    // int height (Node* root){
    //     if (root == NULL)
    //         return 0; 
    //     int h1 = height (root -> left);
    //     int h2 = height (root -> right); 
    //     int ans = max(h1,h2) + 1; 
    //     return ans; 
    // }
    pair<bool,int> checkBalance (Node* root){
        if (root == NULL)
            return {true,0}; 
        bool c1 = false;
        //so we store the information about left subtree through one call only
        //same with right tree.
        //then we access the information through first and second. 
        pair<bool,int> left = checkBalance (root ->left); 
        pair<bool,int> right = checkBalance (root ->right); 
        int ans1 = max(left.second,right.second) + 1; 
        if (abs (left.second - right.second) <= 1)
            c1 = true; 
        if (c1 && left.first && right.first){
            return {true,ans1};
        }
        else 
            return {false,ans1}; 
    }
    bool isBalanced(Node* root) {
        // to check if a tree is balanced, we need to see 
        //1. For the root node, the height of left tree - height right tree <=1 
        //2.Left subtree is balanced. 
        //3.right subtree is balanced.
        //this is necessary as we need to check each node of the tree, not just the root. 
        //One approach is to call the height function for left and right subtrees, and then compute 
        //the abs diff between them. and then call the is balnced function for the left and the 
        //right subtrees. If all conditions are true, return true else return false. 
        //this is o(n2) as for every node, height and isbalnced functions both are called. 
    //     if (root == NULL)
    //         return true; 
    //     int h1 = height (root ->left); 
    //     int h2 = height (root -> right); 
    //     bool condition1 = false; 
    //     if (abs (h1-h2) <= 1){
    //         condition1 = true; 
    //     }
    //     bool condition2 = isBalanced(root -> left);
    //     bool condition3 = isBalanced(root -> right);
    //     if (condition1 && condition2 && condition3)
    //         return true; 
    //     else 
    //         return false; 
    // }
        if (checkBalance(root).first)
            return true; 
        else 
            return false; 
    }
};