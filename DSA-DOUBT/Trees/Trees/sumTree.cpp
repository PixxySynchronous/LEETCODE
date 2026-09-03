Sum Tree
Solved
Difficulty: MediumAccuracy: 37.17%Submissions: 290K+Points: 4
Given the root of a Binary Tree with n nodes, check whether it is a Sum Tree and return true if it is, otherwise return false.

A Sum Tree is a Binary Tree in which the value of every non-leaf node is equal to the sum of all nodes present in its left and right subtrees. An empty tree and a leaf node are also considered Sum Trees.

Examples:

Input: root[] = [3, 1, 2]
 
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore, the given binary tree is a sum tree.
Input: root[] = [10, 20, 30, 10, 10]
 
Output: false
Explanation: The given tree is not a Sum Tree. For the root node, the sum of nodes in the left and right subtrees is 40 + 30 = 70, which is not equal to the root value 10.

/* Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  //Below approach is o(n2)
    // int calcSum (Node* node){ //Gives sum of left subtree and right subtree and the node itself. 
    // //Node itself is included. 
    //     if (node == NULL)
    //         return 0; 
    //     int sumLeft = calcSum (node->left); 
    //     int sumRight = calcSum (node->right);
    //     int sum = sumLeft + sumRight; 
    //     return sum+node->data; 
    // }
    // bool isSumTree(Node* node) {
    //     // calculate sum of the left subtree and right subtree. Compare with root data. 
    //     //Do this recursively. 
    //     if (node == NULL)
    //         return true; //NULL tree is considered SUM tree acc to qsn 
    //     if (node->left == NULL && node->right == NULL)
    //         return true; //For leaf nodes, if this condition is not added,  we will get 
    //         //false for all leaf nodes. As calcSum(NULL) + calcSum(NULL) = 0 != node->data.
    //         //But leaf nodes are considered to be sum trees and hence we write this. 
    //     int sumLeft = calcSum (node->left); 
    //     int sumRight = calcSum (node->right);
    //     int sum = sumLeft + sumRight; 
    //     if (node -> data == sum){
    //         //If root is sumTree, we need to check if the left and the right subtrees are sumtrees as well. 
    //         bool c1 = isSumTree(node->left);
    //         bool c2 = isSumTree(node->right); 
    //         return c1 && c2; 
    //     }
    //     else
    //         return false; 
    
    // }
    pair <bool,int> checkSum (Node* node){
        //Here sum includes the node itself
        //for null roots, sum is 0 and they are considered sumTrees. 
        if (node==NULL){
            return {true,0}; 
        }
        //leaf Nodes need to return true so handeled separetly. 
        if (node->left == NULL && node->right == NULL){
            return {true,  node->data};
        }
        
        pair<bool,int> left = checkSum (node->left); 
        pair<bool,int> right = checkSum (node->right); 
        int sumLeft = left.second; 
        int sumRight = right.second; 
        int sum = sumLeft+sumRight; 
        if (sum == node -> data ){
            bool c1 = left.first;
            bool c2 = right.first; 
            return {c1&&c2, sum+node->data};
        }
        else
            return {false, sum+node->data};
    }
    bool isSumTree (Node* node){
        return checkSum(node).first; 
    }
};