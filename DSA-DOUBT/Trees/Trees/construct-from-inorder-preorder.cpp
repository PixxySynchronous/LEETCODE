// Construct Tree from Inorder & Preorder
// Solved
// Difficulty: MediumAccuracy: 34.59%Submissions: 216K+Points: 4Average Time: 20m
// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the binary tree and return its root.

// Note: The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.  

// Examples:

// Input: inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [0, 1, 2, 3, 4, 5]
// Explanation: The tree will look like
/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* solve (vector<int> inorder, vector<int> preorder, int& preIndex, int startInorder, int endInorder, unordered_map <int,int>& mp){
        //base case is if startInorder>endInorder, it means no search space. 
        if (startInorder > endInorder || preIndex > inorder.size()-1)
            return NULL; 
        int rootVal = preorder[preIndex]; 
        preIndex++; 
        Node* temp = new Node (rootVal); 
        int position = mp[rootVal]; //map has the index of all nodes in inorder stored. 
        temp -> left = solve (inorder, preorder, preIndex, startInorder, position - 1, mp); 
        temp -> right = solve (inorder, preorder, preIndex, position+1,endInorder, mp); 
        return temp; 
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // Easy to do once you know what to do.
        //Preorder is root, left, right.  Therefore the first element of the entire
        //array is the root of the tree. We find that root in the inorder array. 
        //Inorder is left root right. So at whatver position we found our root,
        //elements from 0 to pos-1 belong to the left of the root and elements from
        //pos+1 till the end belong to the right subtree. 
        //Then recursive calls solve the question for both the trees. 
        //SO we need to pass the preorder Index (intially 0 as the main root of the entire tree)
        // and we also need to pass the starting and ending index of the inorder arrays to 
        //define the correct search space (0-position -1 or position +1 till end). 
        //To locate position, we need a hash_map for o(1) lookup time. 
        int n = inorder.size(); 
        unordered_map <int,int> mp; 
        for (int i = 0; i<n; i++){
            mp[inorder[i]] = i; 
        }
        int preIndex = 0; 
        Node* ans = solve (inorder, preorder, preIndex, 0, n-1, mp); 
        return ans; 
    } //Tc = Sc = o(n). 
};