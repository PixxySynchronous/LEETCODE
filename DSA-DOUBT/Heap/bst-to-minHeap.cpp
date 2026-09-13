
// Problem
// Submissions
// Hints & solutions
// Discuss
//  Convert BST to Min Heap
// Moderate
// 80/80
// Average time to solve is 25m
// 68 upvotes
// Asked in companies
// Problem statement
// You are given a 'ROOT' of a binary search tree of integers. The given BST is also a complete binary tree.

// Your task is to convert the given binary search tree into a Min Heap and print the preorder traversal of the updated binary search tree.

// Note:

// Binary Search Tree is a node-based binary tree data structure that has the following properties:

// 1. The left subtree of a node contains only nodes with keys lesser than the node’s key.
// 2. The right subtree of a node contains only nodes with keys greater than the node’s key.
// 3. The left and right subtree each must also be a binary search tree.

// A Binary Heap is a Binary Tree with the following property:

// 1. It’s a complete tree (all levels are filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

// A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to Min Heap.
// For example:

// Given:- BST’s ‘ROOT’ = 4 2 6 -1 -1 -1 -1 
// Then the min-heap in pre-order fashion would be 2 4 6.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 1
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 10 7 11 1 8 -1 -1 -1 -1 -1 -1 
// Sample Output 1:
// 2 5 6 7 8 10
// 1 7 8 10 11
// Explanation of sample input 1:
// Test-Case 1 : 
// Converting the BST into min-heap and its pre-order printing would look like: 2 5 6 7 8 10.

// Test-Case 2 :
// Converting the BST into min-heap and its pre-order printing would look like: 2 5 6 7 8 10.
// Sample Input 2:
// 2
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 2 1 3 -1 -1 -1 -1
// Sample Output 2:
// 1 2 3 4 5 6 7
// 1 2 3    

#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inOrder (vector<int> & inorder, BinaryTreeNode* root){
	if(root == NULL)
		return; 
	inOrder(inorder, root -> left); 
	inorder.push_back(root -> data); 
	inOrder(inorder, root -> right);
}

BinaryTreeNode* preOrderfilling (vector<int>& inorder, BinaryTreeNode* root, int &index){
	if (root == NULL)
		return NULL;
	root -> data = inorder [index]; //preorder deals with root first. 
	index++; 
	root -> left = preOrderfilling (inorder,root->left, index);
	root -> right = preOrderfilling (inorder,root->right, index);
	return root; 
}


BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Since this tree is already a complete binary We just need to insert the values in 
	// a proper way to make sure the condition of min heap is satisfied. 
	// One way to do this is to first find the inorder traverdsal of the bst which gives 
	// us a sorted array.  
	// Now if we traverse those values in a way where root<left and root <right we have solved our qsn 
	vector<int> inorder ; 
	inOrder(inorder, root); 
	// Now if we traverse this sorted array in preorder fashion we fill in the root values first. 
	// And since arr is sorted nd root is being filled first, it is gauranteed to have the smallest element
	// followed by left then right.  SO root<left<right 
	// Notice preorder traversal allows us to preserve the left val<right val. 
	// For this qsn level order traversal also works. But qsn asks for preorder. 
	int index = 0; 
	return preOrderfilling (inorder,root, index); 
	
}
