// 450. Delete Node in a BST
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Deleting a node from BST has 3 case. 
    // If node to be deleted is just a leaf node then simply delete the node and return NULL
    // If node has one child, store the child t=in a temp node, delete the node, return Temp
    // If node has 2 children then we have two options:
        //STEP 1: REPLACE the root to be deleted's value with the value of either the min val in the right or the max value in the left. 
        //STEP2: delete the node with the value. 
    TreeNode* min (TreeNode* root){
        //To get min value, keep on searching left, return the most left element. 
        TreeNode* temp = root; 
        while (temp -> left != NULL)
            temp = temp -> left; 
        return temp; 
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( root == NULL)
            return NULL; 
        if (root -> val == key ){
            //case 1: No child
            if (root -> left == NULL && root -> right == NULL){
                //delete the node and return
                delete root;
                return NULL; 
            }
            //case 2: one child 
                //left child 
            else if (root -> left != NULL && root -> right == NULL){
                TreeNode* temp = root ->left; 
                delete root; 
                return temp; 
            }
                //right child
            else if (root -> right != NULL && root -> left == NULL){
                TreeNode* temp = root ->right; 
                delete root; 
                return temp; 
            }
            //case 3 : 2 children. Lets go with right subtree min value. 
            else {
                int minRight = min(root -> right) -> val; 
                root -> val = minRight; 
                //Now delete the node whose value we copied. 
                root -> right = deleteNode( root ->right, minRight); 
                return root;  
            }
        }
        else if (root -> val > key){ // search left
            // we will have to modify and delete from left tree of root 
            root -> left = deleteNode (root -> left, key); 
            //deletion done
            return root; 
        }

        else {
            // we will have to modify and delete from right tree of root 
            root -> right = deleteNode (root -> right, key); 
            //deletion done
            return root; 
        }
    }
};

//TC is o(h) the maximum number of nodes you can visit is essentially the length of the path from the root to the deepest node.
//SC is o(h) for the recursion stack.