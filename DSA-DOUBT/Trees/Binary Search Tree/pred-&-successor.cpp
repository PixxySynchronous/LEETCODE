// roblem statement
// You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.



// Your task is to return the predecessor and successor of the given node in the BST.



// Note:
// 1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.

// 2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.

// 3. The node for which the predecessor and successor will not always be present. If not present, you can hypothetically assume it's position (Given that it is a BST) and accordingly find out the predecessor and successor.

// 4. A binary search tree (BST) is a binary tree data structure which has the following properties.
//      • The left subtree of a node contains only nodes with data less than the node’s data.
//      • The right subtree of a node contains only nodes with data greater than the node’s data.
//      • Both the left and right subtrees must also be binary search trees.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
// 10
// Sample output 1:
// 8 12
// Explanation of Sample output 1:
// The tree can be represented as follows:

// The inorder traversal of this tree will be 8 10 12 15 16 20 25.

// Since the node with data 8 is on the immediate left of the node with data 10 in the inorder traversal, the node with data 8 is the predecessor.

// Since the node with data 12 is on the immediate right of the node with data 10 in the inorder traversal, the node with data 12 is the successor.
// Sample Input 2:
// 10 5 -1 -1 -1
// 5
// Sample output 2:
// -1 10
// Constraint :
// 1 <= N <= 10^4
// 1 <= data <= 10^7

// Time Limit: 1 sec
// C++ (g++ 5.4)
// 27282930313233343536373839404142434445464748495051525354555657
// /*************************************************************

//     Following is the Binary Tree node structure
//     class TreeNode
//     {
//     public:
//         int data;
//         TreeNode *left, *right;
//         TreeNode() : data(0), left(NULL), right(NULL) {}
//         TreeNode(int x) : data(x), left(NULL), right(NULL) {}
// …            curr = curr -> right; 
//         }

//     }
//     return {pred,succ};
// }


/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // the predecessor of any element is the max element in its left branch. 
    // but if the left branch doesnt exist, then it is their ancestor, 
    // same with the successor, which is equal to min element in its right branch, 
    // but if it doesnt exist then itll be its parent. 
    // if there is no left subtree, predecessor is the nearest ancestor whose value is smaller than key.
    // If there is no right subtree, successor is the nearest ancestor whose value is greater than key.
    int succ = -1; 
    int pred =  -1; 
    TreeNode* curr = root; 
    while (curr != NULL){
        if (curr->data == key){
            if (curr -> left != NULL){ //pred is max in left. 
                TreeNode* temp = curr->left;
                while (temp->right != NULL)
                    temp = temp->right;
                pred = temp->data;
            }
            if (curr -> right != NULL){
                TreeNode* temp = curr->right;
                while (temp->left != NULL)
                    temp = temp->left;
                succ = temp->data;
            }
            break; 
        }
        else if (key< curr -> data){
            //if key is less, we will search the left of the curr. 
            //and if the left of curr dont exist, its pred will be the curr elem. 
            succ = curr -> data; 
            curr = curr -> left; 
        }
        else {
            pred = curr -> data; 
            curr = curr -> right; 
        }

    }
    return {pred,succ};
}
