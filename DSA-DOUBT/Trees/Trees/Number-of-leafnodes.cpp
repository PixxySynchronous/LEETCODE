//Qsn is to count number of leaf nodes
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
//parameter has call by reference to the count variable so fort each recursive call only a single count variable is updated. 
void inorder (BinaryTreeNode<int> *root, int &count){
    if (root == NULL )
        return; 
    //inorder means left, root, right. 
    inorder(root->left, count);
    if (root -> left == NULL && root -> right == NULL){
        count++; 
    } 
    inorder (root ->right, count); 
    return;  
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count = 0;
    //traverse the tree through any traversal method. 
    inorder (root, count); 
    return count; 
}
//since we traverse all nodes once, time complexity is o(n). 
//SPACE COMPLEXITY:
//
// We are using recursion, so every recursive function call
// takes some space in the recursion/call stack.
//
// Example of a skewed tree:
//
//        1
//       /
//      2
//     /
//    3
//   /
//  4
//
// While traversing, the stack can look like:
//
//  ???????????????
//  ? inorder(4)  ?
//  ???????????????
//  ? inorder(3)  ?
//  ???????????????
//  ? inorder(2)  ?
//  ???????????????
//  ? inorder(1)  ?
//  ???????????????
//
// Maximum number of calls in the stack = height of tree (H)
//
// Therefore:
// Space Complexity = O(H)
//
// Balanced tree ? H ? log(N) ? O(log N)
// Skewed tree   ? H ? N    ? O(N)  [worst case]
//
// We don't count the tree itself because it was already given.
// We only count the EXTRA memory used by our recursion.