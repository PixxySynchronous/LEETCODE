//  Flatten BST To A Sorted List
// Moderate
// 72/80
// Average time to solve is 30m
// Contributed by
// 107 upvotes
// Asked in companies
// Problem statement
// You have been given a Binary Search Tree (BST). Your task is to flatten the given BST to a sorted list. More formally, you have to make a right-skewed BST from the given BST, i.e., the left child of all the nodes must be NULL, and the value at the right child must be greater than the current node.

// A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values in the node's left subtree and less than those in its right subtree.

// Follow Up :
// Can you solve this in O(N) time and O(H)  space complexity?
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 100
// 1 <= N <= 5000
// 0 <= node.data <= 10^9, (where node data != -1)

// Where 'N' denotes the number of nodes in the given tree.

// Time Limit: 1 second
// Sample Input 1
// 2
// 10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
// 5 -5 8 -1 -1 -1 -1
// Sample Output 1
// 2 -1 6 -1 8 -1 10 -1 11 -1 12 -1 15 -1 -1
// -5 -1 5 -1 8 -1 -1
// Explanation for Sample Input 1
// For the first test case, the given BST is depicted below.

// So, after flattening, the BST is transposed as the below figure.


// For the second test case, the given BST is depicted below.

// So, after flattening, the BST is transposed as the below figure.


// Sample Input 2
// 2
// 5 3 7 -1 -1 6 8 -1 -1 -1 -1
// 2 1 -1 -1 -1
// Sample output 2
// 3 -1 5 -1 6 -1 7 -1 8 -1 -1
// 1 -1 2 -1 -1
// C++ (g++ 5.4)
// 22232425262728293031323334353637383940414243444546474849505152
//         TreeNode<T> *right;

//         TreeNode(T data) {
//             this -> data = data;
//             left = NULL;
//             right = NULL;
//         }

//         ~TreeNode() {
//             if(left)

// Last saved at 7:41 PM

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inOrder (TreeNode<int>* root, vector<TreeNode<int>*> &inorder){
    if (root == NULL)
        return; 
    inOrder (root -> left, inorder); 
    inorder.push_back(root); 
    inOrder (root ->right, inorder); 
    return; 
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    //We store the Nodesin the inorder array. Make one pointer null and other point to the next node. 

    vector<TreeNode<int>*> inorder; 
    inOrder (root, inorder); 
    int i = 0;
    for ( ; i<inorder.size() -1 ; i++){
        inorder[i] -> left = NULL; 
        inorder[i] -> right = inorder[i+1]; 
    }
    //Last element must point to nothing so handelled alag se. 
    inorder[i] -> left = NULL; 
    inorder [i] -> right = NULL; 
    return inorder[0]; 
}

