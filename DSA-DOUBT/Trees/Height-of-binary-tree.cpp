Height of Binary Tree
Solved
Difficulty: EasyAccuracy: 78.58%Submissions: 369K+Points: 2Average Time: 15m
Given the root of a binary tree, find the maximum depth of the tree.

Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.

Examples:

Input: root = [12, 8, 18, 5, 11]

Output: 2
Explanation: One of the longest path from the root(node 12) goes through node 8 to node 5, which has 2 edges.

/* Structrue of Binary Tree Node
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
    int height(Node* root) {
        // what we do is simple. Considering the root, we have 2 subtrees beneath
        //Height of the tree would be the height of the max height of these 2 subtrees
        //+1. We can simply use recurision to do this. 
        if (root == NULL)
            return -1;  //here we are taking -1 as we need to return the number of edges between the root and the most indepth node, not the height. 
        //the above base case tells that if we reach the leaf node, and then another recursion
        //call is made, we get ans as 0 as height of a tree with no nodes is 0. SO hence the height of the leaf
        //node becomes max(0,0)+1 = 1, which is returned in the later calls. 
        int h1 = height ( root -> left);
        int h2 = height (root -> right); 
        int h = max (h1,h2) + 1 ; 
        return h; 
        //TC: visiting every node once so o(n).
        //SC: O(h) as max number of recursive calls stacked would equal to the hegiht of tree. 
    }
};