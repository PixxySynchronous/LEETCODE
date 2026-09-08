//  Size of Largest BST in Binary Tree
// Easy
// 40/40
// Average time to solve is 10m
// Contributed by
// 177 upvotes
// Asked in companies
// Problem statement
// You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to return the size of the largest subtree of the binary tree which is also a BST.



// A binary search tree (BST) is a binary tree data structure which has the following properties.

// • The left subtree of a node contains only nodes with data less than the node’s data.
// • The right subtree of a node contains only nodes with data greater than the node’s data.
// • Both the left and right subtrees must also be binary search trees.


// Example:
// Given binary tree:

// In the given binary tree, subtree rooted at 2 is a BST and its size is 3.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 2 1 3 -1 -1 -1 -1
// Sample Output 1:
// 3
// Explanation for Sample 1:
// In the given binary tree, subtree rooted at 2 is a BST and its size is 3.

// Sample Input 2 :
// 50 -1 20 -1 30 -1 40 -1 50 -1 -1
// Sample Output 2:
// 4
// Constraints :
// 1 <= 'N' <= 10^5
// 0 <= 'data' <= 10^5     

// where 'N' is the number of nodes and 'data' denotes the node value of the binary tree nodes.

// Time limit: 1 sec
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class info {
    public:
        int maxi; 
        int mini; 
        bool isBST; 
        int size; 
}; 
info solve (TreeNode* root, int &ans){
    if (root == NULL){
        // since data return type is same as the class, we need ton return a data type of the class. 
        // so we define a var, set its parameteres and return it. 
        info currNode; 
        currNode.maxi = INT_MIN; 
        currNode.mini = INT_MAX;
        currNode.isBST = true; 
        currNode.size = 0; 
        return currNode; 
    }
    info left = solve (root -> left, ans); //first make left
    info right = solve (root -> right ,ans); //then make right. 
    info currNode; // then start defining parameters of currNode. 
    currNode.maxi = max (root -> data, right.maxi); 
    currNode.mini = min (root -> data, left.mini); 
    currNode.size = left.size+right.size+1; 
    if (left.isBST && right.isBST && root -> data > left.maxi && root-> data < right.mini){
      currNode.isBST = true;  //need the above conditons to be true to make sure that this node is bst. 
      ans = max (ans, currNode.size); //if it is a bst, update value of ans. 
      return currNode; 
    }
    else{
         currNode.isBST = false;
         return currNode;  
    }

}
int largestBST(TreeNode * root){
    // Approach 1 is to visit every node and check if its a valid bst. Return its size. 
    // But that is o(n2) as we visit every node and then the nodes underneath it to check for validity. 
    // Approach 2 is the optimal approach. For a node, we need to see if left subtree is bst, then right, then check
    // if the node value is greater than the max value of the left subtree and less the least value in the right subtree. 
    // SO we need : isbalanced, maxelem, minelem, size. We need to pass these 4 every call .
    int maxSize = 1; 
    info ans = solve (root, maxSize); 
    return maxSize; 

}