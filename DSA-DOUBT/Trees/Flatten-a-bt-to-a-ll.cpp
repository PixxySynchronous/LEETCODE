// Flatten Binary Tree to Linked List
// Solved
// Difficulty: MediumAccuracy: 75.82%Submissions: 51K+Points: 4
// Given the root of a binary tree, flatten the tree into a Linked list:

// The linked list should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The linked list nodes should be in the same order as a preorder traversal of the binary tree.
// Examples:

// Input: root[] = [1, 2, 5, 3, 4, 6]

// Output: [1, 2, 3, 4, 5, 6]  
// Explanation: After flattening, the tree looks like:
//      1
//       \
//        2
//         \
//          3
//           \
//            4
//             \ 
//              5 
//               \
//                6
// Here, left of each node points to NULL and right contains the next node in preorder.The inorder traversal of this flattened tree is 1 2 3 4 5 6.
// /* Binary Tree Node Structure
// class Node {
// public:
//     int key;
//     Node* left;
//     Node* right;

//     Node(int key) {
//         this->key = key;
//         left = right = nullptr;
//     }
// };
// */

// class Solution {
//   public:
//     void flatten(Node* root) {
//         // We can see that we need to traverse the root, then its left subtree and then its right subtree
//         // However since we need to make it a ll, we only need one pointer, and since we need to go to the left
//         // first, we need to abolish each node's right pointer. But this would mean that the right subtree would be lost. 
//         // To preserve the right subtree, we use moris traversal. Find the predecessor and point its right to the curr->right.
//         // Since now curr -> right is saved, we can simply do curr ->right = curr -> left and curr -> left == NULL
//         Node* curr = root; 
//         while (curr != NULL){
//             if (curr -> left == NULL){
//                 curr = curr -> right; 
//             }
//             else {
//                 Node* pred = curr -> left; 
//                 while (pred ->right != NULL)
//                     pred = pred -> right; 
//                 pred -> right = curr -> right; //connect the rightmost node of left subtree to the first node of right subtree
//                 curr -> right = curr -> left; 
//                 curr -> left = NULL; 
//                 curr = curr -> right; 
//             }
//         }
//         //TC: o(n) and SC o(1)
    
        
//     }
// };