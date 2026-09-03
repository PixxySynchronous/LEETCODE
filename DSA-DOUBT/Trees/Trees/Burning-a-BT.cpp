// Burning Tree
// Solved
// Difficulty: HardAccuracy: 53.53%Submissions: 153K+Points: 8
// Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

// Note: The tree contains unique values.

// Examples : 

// Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
  
// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec 
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.

/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node* createMap (Node* root, int target, unordered_map<Node*, Node*>& mp){
        queue<Node*> q; 
        q.push(root); 
        mp[root] = NULL;
        Node* ans; 
        while (!q.empty()){
            Node* temp = q.front(); 
            q.pop(); 
            if (temp-> left){
                mp[temp->left] = temp; 
                q.push(temp->left); 
            }
            if (temp -> right){
                mp [temp->right] = temp;   
                q.push(temp->right); 
            }
            if (temp -> data == target)
                ans = temp; 
            
        }
        return ans; 
        
    }
    int solve (Node* root, unordered_map <Node*, Node*>& mp){
        unordered_map <Node*, bool> burnt; 
        burnt[root] = true; 
        int time = 0; 
        queue<Node*> q; //we use queue to traverse the tree because that is how a fire spreads. 
        //If we used DFS, it will explore one branch till the end first, but that is not how the fire spreads, 
        ///the fire is spreading level by level and hence a queue (BFS) approach is needed. 
        q.push (root); //We start with the target node. 
        while (!q.empty()){
            //whenever this loop starts, the queue will have all the elements which will burn in time t. 
            //Eg In first go the loop only has the root. So at time 0 only the root burns. 
            //When the next loop starts, the queue will have the 2 children of the root node and its parent,
            //all 3 of which will burn in time = 1. 
            //To keep a record of which elements are to be processed at any burning time t, we use a for loop. 
            int size = q.size(); //number of elements to be burnt at time t. We take this now, as later we will add elements which need to be processed at a later time, 
            bool flag = false; //Keeps track of any elements being added in the queue or not. If no elements were added, we dont increment time. 
            for (int i = 0; i<size; i++){
                Node* temp = q.front(); 
                q.pop(); 
                
                if (temp->left && burnt[temp->left] == false){
                    q.push(temp->left);
                    burnt[temp -> left] = true; 
                    flag = true; 
                }
                
                if (temp->right && burnt[temp->right] == false){
                    q.push(temp->right);
                    burnt[temp -> right] = true; 
                    flag = true; 
                }
                
                if (mp[temp]!= NULL && burnt[mp[temp]] == false){
                    q.push(mp[temp]);
                    burnt[mp[temp]] = true;
                    flag = true; 
                }
            }
            if ( flag == true)
                time++; 
        }
        return time; 
    }
    int minTime(Node* root, int target) {
        // Logic of the code is this.
        //Once you are on your target node. 3 nodes are supposed to burn, left child, right child,
        //and the parent of the node. 
        //We can access the children but to access the parent node we make a mapping. 
        //If the node is already burnt, we dont have to process it so we need to keep a visited mapping aswell
        //If all 3 options of the node are already burnt, we dont increment time. Time is incremented only if something new is burnt. 
        //Therefore a flag variable keeps in account if anything, which hasnt already been visited, is added into the queue. If it is, 
        //then only then is the time variable incremented. 
        unordered_map <Node*, Node*> mp; //Parent child node mapping. 
        Node* targetNode = createMap (root, target, mp); //The parent child mapping is created and the target node is returned. 
        int ans = solve (targetNode, mp); 
        return ans; 
        
        
    }
};