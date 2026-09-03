/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/
BinaryTreeNode<int>* search (BinaryTreeNode<int> *root, int x){
    if ( root == NULL )
        return NULL; 
    if (root -> data == x)
        return root;
    else if ( root -> data > x){
        return search ( root -> left, x);
    }  
    else   
        return search ( root -> right, x); 
    

}
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *ans = search ( root, x); 
    if (ans) return true;
    else return false; 
}

//TC is o(h) the maximum number of nodes you can visit is essentially the length of the path from the root to the deepest node.
// sc is o(h) for the recursion stack.