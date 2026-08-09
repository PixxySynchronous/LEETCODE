Identical Trees
Solved
Difficulty: EasyAccuracy: 50.01%Submissions: 315K+Points: 2Average Time: 15m
Given two binary trees with their root nodes r1 and r2, return true if both of them are identical, otherwise return false.
Note: Two trees are identical when they have the same data and the arrangement of the data is also same.

Examples:

Input: r1 = [1, 2, 3, 4], r2 = [1, 2, 3, 4]

Output: true
Explanation: Trees are identical.
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // check the value of the current node.
        //Call the function for the left node and then the right node. 
        //if root is NULL, we cant access root->data, or this causes segmentation fault. 
        if (r1 == NULL && r2 != NULL)
            return false; 
        if (r1 != NULL && r2 == NULL)
            return false; 
        if (r1 == NULL && r2 == NULL)
            return true; 
        if (r1 -> data == r2 -> data){
            bool c1 = isIdentical(r1->left, r2->left);
            bool c2 = isIdentical(r1->right, r2->right); 
            if (c1 && c2)
                return true; 
        }
        return false; 
        
    }
    //TC: o(N) and SC: o(H)
};