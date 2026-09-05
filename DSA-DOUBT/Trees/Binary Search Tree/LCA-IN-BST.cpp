/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    //a node will be the ancestor of both the given nodes if one of the nodes is ppresent
    //on its left subtree and the other is in its right subtree. 
    //Due to the property of BST we dont have to search the entire left and right subtrees
    // to find the nodes. We can just compare the data of the root with the nodes. 
    TreeNode* curr = root; 
    while (curr != NULL){
        if (curr -> data > P->data && curr -> data > Q-> data)
            curr = curr -> left; //since root value is bigger than both, both nodes will be to its left. 
        else if (curr -> data < P->data && curr -> data < Q-> data)
            curr = curr -> right; //since root value is smaller than both, both nodes will be to its right. 
        else    
            return curr; //one of them is smaller in value and other one is bigger in value, hence this node is the LCA. 
    }
    return NULL; 
}
//TC is o(h) the maximum number of nodes you can visit is essentially the length of the path from the root to the deepest node.
// sc is o(1) since we are not using any extra space.