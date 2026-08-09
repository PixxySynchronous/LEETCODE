Diameter of a Binary Tree
Solved
Difficulty: MediumAccuracy: 47.37%Submissions: 377K+Points: 4Average Time: 20m
Given the root of a binary tree, find the diameter of the binary tree. The diameter of a binary tree is defined as the number of edges on the longest path between any two nodes. Note that this path may or may not pass through the root of the tree.

Examples:

Input: root = [1, 2, N, 3, 4]

Output: 2
Explanation: The longest path has 2 edges (node 3 -> node 2 -> node 4).
/*Structure of binary tree Node 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    // int height (Node* root){
    //     if (root == NULL)
    //         return -1; //counting number of edges in this qsn. 
    //     int h1 = height (root ->left);
    //     int h2 = height (root -> right);
    //     int ans = max(h1,h2) + 1; 
    //     return ans; 
    // }
    // int diameter(Node* root) {
    //     if (root == NULL)
    //         return 0; 
    //     // Diameter of a tree is consdired to be the longest path between any 2 end nodes. 
    //     //This diameter can be present entirely in the left subtree, right subtree, or start from left subtree,
    //     //go through the root, and end in the right subtree. So for all cases, all we need to do ios calculate these
    //     //3 options. 
    //     int o1 = diameter (root ->left); 
    //     int o2 = diameter (root -> right); 
    //     int o3 = height (root -> left) + height (root -> right) + 2; 
    //     // since we are counting the number of edges in this question, for option 3,
    //     //diameter would be the height of left subtree plus height of right subtree 
    //     //plus one edge connecting the root to the left subtree and one edge connecting to 
    //     //the right subtree. 
    //     int ans = max (o1, max (o2,o3)); 
    //     return ans; 
    //     //TC: o(n2) as we are calling height function for every node, so we visit all nodes twice.
    //     //Optimised approach is below: 
    // }
    int height (Node* root, int &diameter){
        if (root == NULL)
            return -1; //counting number of edges in this qsn. 
        int h1 = height (root ->left, diameter); //calculate the left subtree height, and option 1.
        int h2 = height (root -> right, diameter);//calculate the right subtree height, and option 2. 
        int currentDiam = h1+h2+2; //calculate option 3. 
        diameter = max(diameter,currentDiam); //update diameter accordingly. 
        int ans = max (h1,h2) + 1; //return the height of the subtree. 
        return ans; 
    }
    int diameter(Node* root) {
        int diameter = 0 ; 
        height(root, diameter);
        return diameter;
        //in this approach one function calculates both diameter and height, so tc becomes o(n)
        //sc is o(height)
    }
};