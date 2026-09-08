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
    TreeNode* preOrdertoBST (int& index, vector<int> & preorder, int& min, int&max){
        if (index >= preorder.size())
            return NULL; 
        if ( preorder[index] < min || preorder[index] > max) //out of bounds for both right and left so retrun NULL
            return NULL; 
        TreeNode* curr = new TreeNode(preorder[index]); //since curr element is inbounds, make it a node. 
        index++; //increase index for next call. 
        curr -> left = preOrdertoBST(index,preorder,min,curr->val); 
        curr -> right = preOrdertoBST(index,preorder,curr->val,max); 
        return curr; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //Approach 1: sort the preorder to make inorder. Then make the tree from inorder. (mid of inorder is root. Elements 0 - mid -1 is root -> left. Elements mid+1 - end is root -> right. Recursively call. )
        // But that is o(NlogN). 
        //Approach 2 is simply making a insertIntoBST function and pass the entire array in it. 
        // Thats o(n2). 
        // Approach 3 is o(n). 
        // Preorder is root, left, right. 
        // So we make the  element at the current index root. 
        // root -> left has a range (-infinty, root->val). See if the next element fits this range. 
        // Similary root -> right has a range.  
        // recursively call
        int max = INT_MAX;
        int min = INT_MIN; 
        int index = 0; 
        return preOrdertoBST (index,preorder,min,max); 
    }
};