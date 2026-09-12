// Is Binary Tree Heap
// Solved
// Difficulty: MediumAccuracy: 34.41%Submissions: 152K+Points: 4
// You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

// A binary tree is considered a max-heap if it satisfies the following conditions:

// Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
// Max-Heap Property: The value of each node is greater than or equal to the values of its children.
// Examples:

// Input: root = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
// Output: true
// Explanation: The tree is complete and satisfies the max-heap property.

/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int countNodes (Node* tree){
        if ( tree == NULL)
            return 0 ; 
        return ( 1+ countNodes(tree -> left) + countNodes (tree -> right)); 
    }
    
    bool isCBT (Node* tree, int index, int count){
        if (tree == NULL)
            return true;
        if (index >= count)
            return false; 
        int leftIndex = 2*index + 1; 
        int rightIndex = 2*index + 2; 
        bool left = isCBT (tree -> left, leftIndex, count); 
        bool right = isCBT (tree -> right, rightIndex, count); 
        return (left&&right); 
    }
    
    bool isMaxHeap (Node* tree){
        if (tree == NULL)
            return true;
        //below base cases are required so as to not get null pointer segment error
        //as we need to make sure that a right child and a left child exist and only then 
        //can we access their data. These basecases fire in the cases when they dont exist. 
        if (tree -> right == NULL && tree -> left == NULL ){
            return true; //leaf nodes follow heap. 
        }
        else if (tree -> right == NULL){
            //only left child. And since we have checked that the tree is a CBT, we know 
            //that if a root has only one child, it will be left and leafnode. Hence we dont 
            //need to check bool left here like we do if both children exist. 
            if (tree -> data > tree -> left -> data)
                return true; 
            else 
                return false; 
        }
        // else if ( tree -> left == NULL){
        // NOT REQUIRED AS WE HAVE CHECKED THAT THE TREE IS A CBT AND A CBT WILL NEVER HAVE
        //ONLY A RIGHT CHILD. 
        //     //only right child
        //     if (tree -> data > tree -> right -> data)
        //         return true; 
        //     else 
        //         return false; 
        // }
        else {
            //both child exist. 
            bool left = isMaxHeap (tree -> left); 
            bool right = isMaxHeap ( tree -> right); 
            if (left && right && tree -> data > tree -> right -> data && 
            tree -> data > tree -> left -> data)
                return true; 
            else return false; 
        }
      
    
    }
    
    bool isHeap(Node* tree) {
        /* to check if a tree is a heap, we need to check 2 things.
        1. It is a complete tree. 
        2. All nodes satify the heap constraint. 
        -> to check the first condition, a tree is said to be complete if none of the indices
        go beyond the number of total nodes. Eg if total nodes are 6 and we have a node at index 7, it means
        we skipped a left somewhere so it is not a CBT. 
        -> second check is just recursion. 
        */
        int count = countNodes (tree); 
        int index = 0 ; //index of root 
        return (isCBT (tree, index,count) && isMaxHeap (tree)); 
        
    }
};
// countNodes()  → O(n)
// isCBT()       → O(n)
// isMaxHeap()   → O(n)