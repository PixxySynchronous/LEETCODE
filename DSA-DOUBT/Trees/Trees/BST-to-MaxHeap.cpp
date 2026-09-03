// BST to max heap
// Solved
// Difficulty: MediumAccuracy: 67.16%Submissions: 29K+Points: 4
// Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

// Example 1:

// Input :
//                  4
//                /   \
//               2     6
//             /  \   /  \
//            1   3  5    7  

// Output : 1 2 3 4 5 6 7 
// Exaplanation :
//                7
//              /   \
//             3     6
//           /   \  /   \
//          1    2 4     5
// The given BST has been transformed into a
// Max Heap and it's postorder traversal is
// 1 2 3 4 5 6 7.

// Your task :
// You don't need to read input or print anything. Your task is to complete the function convertToMaxHeapUtil() which takes the root of the tree as input and converts the BST to max heap.
// Note : The driver code prints the postorder traversal of the converted BST.
/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
    //inorder traversal of a BST will give me a sorted array. 
    //To make this sorted array a max heap, we need to traverse it in 
    //post order traversal. (As the first element will be the smallest, and third
    //the largest, as array is sorted.)
    void inOrder (Node* root, vector<int> &arr){
        if (root == NULL)
            return; 
        inOrder (root -> left, arr);
        arr.push_back(root -> data); //store the sorted array
        inOrder (root -> right, arr); 
        return; 
    }
    
    void postOrder (Node* root, vector<int> &arr, int &index){
        if (root == NULL)
            return; 
        postOrder (root -> left, arr,index);
        postOrder (root -> right, arr, index);
        root -> data = arr[index]; //traverse the sorted array. 
        index++; 
    }
  public:
    void convertToMaxHeapUtil(Node* root) {
        vector <int> arr; 
        inOrder (root, arr); 
        int index = 0 ; 
        postOrder (root,arr,index); 
        return; 
    }
};
