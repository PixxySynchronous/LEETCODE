// Sum of nodes on the longest path
// Solved
// Difficulty: MediumAccuracy: 52.39%Submissions: 131K+Points: 4
// Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

// Examples:

// Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
 
// Output: 13
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve (Node* root, int& maxLength, int length, int& maxSum, int sum){
        if (root == NULL){//we have reached the end of a path. Now we check the length and the 
        //with the maxLength. 
            if (length > maxLength){//then simply make maxSum as sum of this path. 
                maxLength = length ; 
                maxSum = sum; 
                return; 
            }
            else if (length == maxLength){
                //then update the highest sum as the max of both the sums. 
                maxSum = max(sum, maxSum); 
                return; 
            } 
            else //the path is not the longest and hence irrelevant.
                return; 
        }
        //if we are not at the end of a path, then we update sum, and length and call function. 
        sum += root ->data; 
        length++; 
        solve (root -> left, maxLength, length, maxSum, sum); 
        solve (root -> right, maxLength, length, maxSum, sum); 
        return; 
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        //Task is simple. We need to retunr the sum of all the nodes in the path having 
        //the most length. If lengths are equal we compare the sums and return the max sum. 
        //SO to do this, whenever we call the function "solve" we update sum += root->data and 
        //length ++. 
        int maxLength = 0; 
        int maxSum = INT_MIN; //will only be updated once we reach a leaf node. 
        int sum = 0 ; 
        int length = 0 ; 
        solve (root, maxLength, length, maxSum, sum);
        return maxSum; 
        
        
    }
};
//Since we visit each node once, time complexity is o(n).
//Space complexity is o(h) as max number of recursive calls stacked would equal to the hegiht of tree.