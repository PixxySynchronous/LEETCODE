//  Find K-th smallest Element in BST
// Easy
// 40/40
// Average time to solve is 15m
// Contributed by
// 76 upvotes
// Asked in companies
// Problem statement
// Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).

// BST ( binary search tree) -

// If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.

// Example -


// Order of elements in increasing order in the given BST is - { 2, 3, 4, 5, 6, 7, 8, 10 }

// Suppose given ‘K = 3’ then 3rd smallest element is ‘4’.

// Suppose given ‘K = 8’ then 8th smallest element is ‘10’.

// Note:
// 1. You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return the ‘K-th’ smallest element of BST.
// 2. You don’t need to return ‘K-th’ smallest node, return just value of that node. 
// 3. If ‘K-th’ smallest element is not present in BST then return -1.
#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve (BinaryTreeNode<int>* root, int k, int &count){

//     if (root == NULL)
//         return -1; 
//     int left = solve (root -> left, k, count);
//     if (left != -1) //the answer was found in the elft subtree, therefore we must propogate the answer upwards.
//         return left; 
//     count++;
//     if (count == k) //if the current node is the answer then propogate it upwards. 
//         return root -> data; 
//     else
//         return solve (root -> right, k, count); //else the ans is bound to be in the right subtree. 
    //***************************************
    //can also be done via morris traversal to use constant space. 
    BinaryTreeNode<int>* curr = root; 
    while ( curr != NULL){
        if (curr -> left == NULL){
            count ++;
            if (k==count)
                return curr-> data; 
            curr = curr -> right; 
        }
        else {
            BinaryTreeNode<int>* pred = curr -> left; 
            while (pred -> right != NULL && pred -> right != curr)
                pred = pred ->right; 
            
            if (pred -> right == NULL){
                pred -> right = curr; 
                curr = curr -> left; 
            }
            else {
                pred -> right = NULL; 
                count ++;
                if (k==count)
                    return curr -> data; 
                curr = curr -> right; 
            }
        }
    }
    return -1; 
 }
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Since duing inorder traversal returns a sorted array, I just need to return the 
    // kth element in it, which i can find by keeping a counter variable.
    int count = 0; 
    int ans = solve (root, k , count); 
    return ans; 
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Since duing inorder traversal returns a sorted array, I just need to return the 
    // kth element in it, which i can find by keeping a counter variable.
    int count = 0; 
    int ans = solve (root, k , count); 
    return ans; 
}

//TC is o(h+k) the maximum number of nodes you can visit is essentially the length of the path from the root to the deepest node + k nodes in the inorder traversal.    