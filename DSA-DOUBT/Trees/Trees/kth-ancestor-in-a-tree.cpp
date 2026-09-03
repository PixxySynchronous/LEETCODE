// Kth Ancestor in a Tree
// Solved
// Difficulty: MediumAccuracy: 35.06%Submissions: 134K+Points: 4
// Given a binary tree with n nodes, a target node value, and a positive integer k, find the kth ancestor of the given node.

// The kth ancestor of a node is the node that lies k levels above it in the tree. If the given node does not have a kth ancestor, return -1.

// Notes

// It is guaranteed that the given node exists in the binary tree.
// All node values in the tree are distinct.
// Examples :

// Input: root = [1, 2, 3, 4, 5], k = 2, node = 4

// Output: 1
// Explanation: The ancestors of node 4 are 2 and 1. Moving 2 levels upward from node 4 reaches node 1, so the output is 1.

/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* solve (Node*root, int& k, int node){
        if (root == NULL)
            return NULL; 
        if (root -> data == node){
            //Node goal found, now we go upwards
            return root; 
        }
        //Note: Once the goal node is found, it is exactly this node which continues to go upwards. 
        //UNTIL the kth ancestor is found. Hence, if kth ancestor is not found, this function returns the 
        //goal node itself. This is why we need an if (ans->data == node) condition in the main function,
        //to indicate that the ancestor wasnt found. 
        //Node goal not found keep searching 
        Node* left = solve (root -> left, k, node);
        Node* right = solve (root -> right, k, node);
        if (left == NULL && right == NULL) //Goal node not found
            return NULL; 
        if (left != NULL && right == NULL) //goal node found in left subtree
        {
            k--; 
            if (k==0){//ancestor found, we need to keep returning this node
                return root; 
            }
            else 
                return left; //keep going up. 
            
        }
         if (right != NULL && left == NULL) //goal node found in right subtree
        {
            k--; 
            if (k==0){//ancestor found, we need to keep returning this node
                return root; 
            }
            else 
                return right; //keep going up. 
            
        }
        return NULL;
        
    }
    int kthAncestor(Node *root, int k, int node) {
        // Logic is VERYYYYYYYYY simple. One approach is the BFS approach where you
        //store the path to reach the node and then return the kth element in the path
        //starting from the end (back of the vector path) but this takes extra space. 
        //What we can do is, find the the node. Itll be in either left subtree or the right
        //subtree.  SO once it is found, return something. So we get the conditions
        //: both left and right is null, we return null 
        //: etiher one of them returns a node,  meaning the goal node is found. 
        //Then everytime we go back (the function call ends) we do k--. 
        //Once k=0, we have found the ancestor and we keep returning that root till all calls end
        //Note: due to recursion, even after k=0, the recursion calls continue and k-- will keep happening. 
        Node* ans = solve (root, k, node); 
        if (ans == NULL || ans->data == node) 
        //since k is bound to be greater than or equal to 1, 
        //if we get root as the node itself, it means that we cant go any upwards, as root has no ancestors,
        //hence we return -1.
            return -1; 
        return ans->data; 
        //Tc : o(N). Each node is visited once, and no further operation is done on that node. 
        //SC; o(h)
    }
};
