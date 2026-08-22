// Maximum Non-Adjacent Nodes Sum
// Solved
// Difficulty: MediumAccuracy: 55.35%Submissions: 104K+Points: 4Average Time: 45m
// Given the root of a binary tree with integer values. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

// Examples:

// Input: root = [11, 1, 2]

// Output: 11
// Explanation: The maximum sum is obtained by selecting the node 11.
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<int,int> solve (Node* root){
        if (root == NULL) //reached the end, both the sums will = 0
            return {0,0};
        pair <int,int> ans; 
        pair <int,int> left = solve (root -> left); 
        pair <int,int> right = solve (root -> right); 
        ans.first = root->data + left.second + right.second; //Including the element 
        ans.second = max(left.first, left.second) + max(right.first, right.second); //excluding it 
        return ans; 
        
    }
    int getMaxSum(Node *root) {
        //This one is a tough nut to crack at first. 
        //So for every node, we can either include the node and then calculate the sum
        //(which means including the node and then not including the nodes beneath but including their children)
        //Or we can exclude the node and then the sum becomes the sum of the nodes beneath this node. 
        //So basically for every node, we have 2 sums. Including the node, or excluding the node. 
        //for every node: <include node, exclude node> -> i have 2 sums 
        // If i choose to include the node. I will take: sum = node -> data + left.second + right.second. 
        //(where second represents the sum of excluding the children nodes)
        // If i choose to exclude the node, Sum will be = max (left.first, left.second) + max (right.first, right.second)
        pair<int, int> ans = solve (root); 
        return max (ans.first, ans.second); 
        
    }
};//tc is o(n) as we visit each node once. 
