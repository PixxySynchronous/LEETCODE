// LCA in Binary Tree
// Solved
// Difficulty: MediumAccuracy: 52.85%Submissions: 217K+Points: 4Average Time: 20m
// Given the root of a binary tree with all unique values and two nodes value, n1 and n2.

// Find the lowest common ancestor of the given two nodes. Both node values are always present in the Binary Tree.

// Note: LCA is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7], n1 = 4, n2 = 5    

// Output: 2
// Explanation: LCA of 4 and 5 is 2.
/* Structure of binary tree node
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
    Node* lca(Node* root, int n1, int n2) {
        // DFS APPROACH: 
        //Check the left subtree of a root for n1 and n2. And then check the right subtree
        //for n1 or n2. If both subtrees dont have either of the vlaues then return NULL as 
        //then the root cant be an ancestor. 
        //If left subtree found one of the values and right subtree didnt, return the value
        //(the root) If right subtree found one of the values and left didnt,return that value. 
        //But if both right and left subtree found the value, then return the root, as that is the least common ancestor. 
        //This works because we are doing a bottom up approach. 
        //Eg in test case 1, we go from 1 then 2 then 4. 4 = n1 so 4 is returned upwards. 
        //then 2->right is called which also returns 5 . Since 2 got left and right , we find that 2 is the LCA.'
        if (root == NULL)
            return NULL; 
        if ((root -> data == n1) || (root -> data == n2))
            return root; 
        Node* left = lca (root -> left, n1, n2); 
        Node* right = lca (root -> right, n1, n2); 
        if ( left != NULL && right != NULL)
            return root; //this is the answer. 
        else if ( left != NULL && right == NULL)
            return left; 
        else if (left == NULL && right == NULL)
            return NULL; 
        else return right; 
        
        //Another BFS approach is perhaps more intuitive. Traverse the tree in BFS, noting down each nodes parent 
        //element in a map. Then for the 2 nodes, find the first common parent. 
    //     Node* LCA(Node* root, Node* p, Node* q) {

    //         // Store parent of every node
    //         unordered_map<Node*, Node*> parent;

    //         queue<Node*> bfs;

    //         bfs.push(root);
    //         parent[root] = NULL;

    //         // BFS traversal
    //         while (!bfs.empty()) {

    //             Node* curr = bfs.front();
    //             bfs.pop();

    //             if (curr->left != NULL) {
    //                 parent[curr->left] = curr;
    //                 bfs.push(curr->left);
    //             }

    //             if (curr->right != NULL) {
    //                 parent[curr->right] = curr;
    //                 bfs.push(curr->right);
    //             }
    //         }

    //         // Store ancestors of p
    //         unordered_set<Node*> ancestors;

    //         while (p != NULL) {
    //             ancestors.insert(p);
    //             p = parent[p];
    //         }

    //         // Move upward from q
    //         while (q != NULL) {

    //             // First common ancestor = LCA
    //             if (ancestors.count(q)) {
    //                 return q;
    //             }

    //             q = parent[q];
    //         }

    //         return NULL;
    //     }
    // }
};

//TC: o(n) as we visit each node once.
//SC: o(h) as max number of recursive calls stacked would equal to the hegiht of tree.
//BFS approach would have SC = o(n) as we store all the parents in a map.
