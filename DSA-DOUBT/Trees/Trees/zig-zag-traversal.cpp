Zig-Zag Tree Traversal
Solved
Difficulty: MediumAccuracy: 54.05%Submissions: 439K+Points: 4Average Time: 30m
Given the root of a binary tree. Find the zig-zag level order traversal of the binary tree.
Note: In zig zag traversal we traverse the nodes from left to right for odd-numbered levels, and from right to left for even-numbered levels.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7]
          
Output: [1, 3, 2, 4, 5, 6, 7]
Explanation:
Level 1 (left to right): [1]
Level 2 (right to left): [3, 2]
Level 3 (left to right): [4, 5, 6, 7]
Final result: [1, 3, 2, 4, 5, 6, 7]

/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // Level order traversal. Just switch the directions every other level. 
        //At a point, in a queue used for level order traversal, the queue has
        //only the elems of 1 level. Once they are processed we put in the child nodes.
        //So we can exploit this.
        //we can use a loop which, for every iteration, sets the direction of traversal
        //for that level. 
        vector<int> result; 
        if (root == NULL)
            return result; 
        queue<Node*> q; 
        bool leftToright = true; 
        q.push(root); 
        while (!q.empty()){
            int size = q.size(); 
            vector<int> ans (size); //need a seperate array each time for each level as size fo each level varies 
            //and we need to access the index of the array to insert from the back. 
            //once the for loop ends, it means we are done with the processing of a level.
            //since we defined size before the for loop started. 
            for (int i = 0 ; i<size; i++){
                Node* front = q.front(); 
                q.pop(); 
                if (leftToright){
                    ans[i] = front->data;
                }
                else{
                    ans[size-i-1] = front -> data; //insert from the back. 
                }
                //These elements which are being inserted are of the next level and wont 
                //be processed in this for loop as we have already defined size fo queue = number of elements
                //in the previous level. 
                if (front -> left)
                    q.push(front ->left); 
                if (front -> right)
                    q.push(front ->right); 
            }
            //Level processed so we flip the flag. 
            leftToright = !leftToright; 
            //Level processed so we store the ans vector in results, as in next loop a separate ans vector will form. 
            for (auto i:ans){
                result.push_back(i); 
            }
        }
        return result; 
        //TC: o(n) as we access each node once. 
        //SC: o(n)
    }
};