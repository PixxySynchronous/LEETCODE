// Binary Tree from Inorder and Postorder
// Solved
// Difficulty: MediumAccuracy: 64.78%Submissions: 93K+Points: 4Average Time: 45m
// Given two arrays representing the inorder and postorder traversals of a binary tree, your task is to construct the binary tree and return its root.

// Note: The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

// Examples:

// Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, N, 8]
// Explanation: For the given inorder and postorder traversal of tree the resultant binary tree will be:

/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
   Node* solve (vector<int> inorder, vector<int> postorder, int& postIndex, int startInorder, int endInorder, unordered_map <int,int>& mp){
       //base case is if startInorder>endInorder, it means no search space. 
       if (startInorder > endInorder || postIndex < 0)
           return NULL; 
       int rootVal = postorder[postIndex]; 
       postIndex--; 
       Node* temp = new Node (rootVal); 
       int position = mp[rootVal]; //map has the index of all nodes in inorder stored. 
      
       temp -> right = solve (inorder, postorder, postIndex, position+1,endInorder, mp);
       temp -> left = solve (inorder, postorder, postIndex, startInorder, position - 1, mp); 
       return temp; 

   }
   Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
       // Easy to do once you know what to do.
       //Postorder is left, right,root. Therefore the last element of the entire
       //array is the root of the tree. We find that root in the Inorder array. 
       //Inorder is left root right. So at whatver position we found our root,
       //elements from 0 to pos-1 belong to the left of the root and elements from
       //pos+1 till the end belong to the right subtree. 
       //Then recursive calls solve the question for both the trees. 
       //But since we are moving backwards in the psotorder array (left right root), we will first
       //call the recursive for root -> right and then call it for root -> left. 
       //SO we need to pass the Postorder Index (intially n-1 as the main root of the entire tree)
       // and we also need to pass the starting and ending index of the inorder arrays to 
       //define the correct search space (0-position -1 or position +1 till end). 
       //To locate position, we need a hash_map for o(1) lookup time. 
       int n = inorder.size(); 
       unordered_map <int,int> mp; 
       for (int i = 0; i<n; i++){
           mp[inorder[i]] = i; 
       }
       int postIndex = n-1; 
       Node* ans = solve (inorder, postorder, postIndex, 0, n-1, mp); 
       return ans; 
   } //Tc = Sc = o(n). 
};