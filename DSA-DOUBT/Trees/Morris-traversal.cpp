//Inorder traversal of a binary tree using morris traversal. NO extra space is used.
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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root; 
        vector<int> result; 
        while (curr != NULL){
            //To do inorder traversal without extra space, we use morris traversal. 
            //Once we find current, we need to find its inorder predecessor. Since inorder
            //traversal is left root right, root's predecessor is iin its left subtree. 
            if(curr -> left == NULL){
                //If there is no left subtree, no predecessor, therefore just record the value and move to the right. 
                result.push_back(curr->val);
                curr = curr -> right; 
            }

            else{ //Left subtree is present. 
            //Predecessor: curr -> left and then right till we reach null. 
            //Once we reach the predecessor, we connect its right to the current node. 
                TreeNode* predecessor = curr -> left; //first left. 
                while (predecessor -> right != NULL && predecessor -> right != curr){ 
                    //go till predecessor right is null. If its a previous predecessor then its right would already be connected to current. If thats the case, we severe that connection. 
                    predecessor = predecessor -> right; 
                }
                //If null -> make connection and move curr to left. 
                if (predecessor -> right == NULL){
                    predecessor -> right = curr;
                    curr = curr -> left;
                }
            //If connection present, remove it, add current to the result and move to right. 
                else{
                    predecessor -> right = NULL;
                    result.push_back (curr -> val);
                    curr = curr -> right;
                } 
                     
            }

        }
        return result; 
//       Time Complexity: O(n), if we take a closer look, we can notice that every edge     of the tree is traversed at most three times.
// Auxiliary Space: O(1)
    }
};