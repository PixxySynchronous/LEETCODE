// Normal BST To Balanced BST
// Moderate
// 80/80
// Average time to solve is 15m
// Contributed by
// 85 upvotes
// Asked in companies
// Problem statement
// You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with the minimum height possible.

// A binary search tree (BST) is a binary tree data structure that has the following properties.

// • The left subtree of a node contains only nodes with data less than the node’s data.
// • The right subtree of a node contains only nodes with data greater than the node’s data.
// • Both the left and right subtrees must also be binary search trees.
// A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.

// For Example:

// For the given BST:

// The modified BST will be:

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 1
// 10 6 -1 4 -1 -1 -1
// Sample output 1:
// 4 6 10
/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inOrder (TreeNode<int>* root, vector<int> &inorder){
    if (root == NULL)
        return; 
    inOrder (root -> left, inorder); 
    inorder.push_back(root -> data); 
    inOrder (root ->right, inorder); 
    return; 
}
TreeNode<int>* inOrdertoBST (int start, int end, vector<int> & inorder){
    if (start>end)  
        return NULL; 
    int mid = (start+end)/2; 
    TreeNode<int>* curr = new TreeNode<int> (inorder[mid]); 
    curr -> left = inOrdertoBST(start,mid-1,inorder);
    curr -> right = inOrdertoBST(mid+1,end, inorder); 
    return curr; 
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // dont matter if the current tree is balanced or not. Just take out its inorder version. 
    // and then cinstruct a balanced tree from it. 
    // essentially this question becomes inorder -> bst.
    // That can be done by this: inorder mid == root. the index 0 - mid - 1 is root -> left. 
    // mid+1 to end is root -> right. solve via recursion. 
    vector<int> inorder; 
    inOrder(root,inorder); 
    return inOrdertoBST (0, inorder.size()-1, inorder); 

}
