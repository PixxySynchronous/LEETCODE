// Tree Boundary Traversal
// Solved
// Difficulty: MediumAccuracy: 23.33%Submissions: 578K+Points: 4Average Time: 35m
// Given a root of a Binary Tree, return its boundary traversal in the following order:

// Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
// Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
// Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.
// Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]
// Explanation:

/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    void traverseLeft (Node* root, vector<int> &ans){
        //base case is if root is NULL or leaf node, we return. 
        if (root == NULL || (root -> left == NULL && root -> right == NULL))
            return; 
        //else we record the roots data and then traverse downwards.
        ans.push_back (root -> data);
        if (root ->left )
            traverseLeft (root ->left, ans); 
        //If there is no left node, then left most node is the right child. 
        else 
            traverseLeft (root -> right,ans); 
        return; 
    }
    
    void traverseLeaf ( Node* root, vector<int> & ans){
        if (root == NULL) return; 
        //if node is a leaf node, then record its value. 
        if (root -> left == NULL && root ->right == NULL)
            ans.push_back (root -> data); 
        else {//not a leaf node
            traverseLeaf (root ->left, ans);
            traverseLeaf (root ->right, ans);
        }
        return;
    }
    
    void traverseRight (Node* root, vector<int> &ans){
        //Since we need to traverse in reverse, we first wanna reach a node whose children nodes are leaf nodes
        //Once we encounter a leaf node, we return null so call goes back to the parent node. 
        //then we record the data of the parent node. 
        if (root == NULL) return; 
        if (root->right)
            traverseRight (root -> right, ans); 
        else 
            traverseRight (root ->left, ans); 
        if ( root -> left == NULL && root -> right == NULL) return; 
        //Now the vall returns to the parent node. 
        ans.push_back (root -> data); 
        return; 
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        if (root == NULL)
            return {}; 
        //First we traverse the root and then 
        // we need 3 separate functions. 
        //One traverses all the left nodes minus the leaf nodes. 
        //One traverses all the leaf nodes. 
        //One traverses all the right nodes but in the reverse order. 
        vector<int> ans; 
        ans.push_back ( root -> data); 
        traverseLeft (root -> left, ans); 
        //Now we travel all the leaf nodes. Leaf nodes are present in both the left 
        //and the right subtree so we need to call the function for both. 
        traverseLeaf(root ->left, ans); 
        traverseLeaf(root ->right, ans); 
        
        //Now we traverse the right nodes.
        traverseRight (root->right, ans); 
        return ans; 
        
    }
};
//TC: o(n) as we visit each node once.
//SC: o(h) as max number of recursive calls stacked would equal to the hegiht of tree.