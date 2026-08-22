// K Sum Paths
// Solved
// Difficulty: MediumAccuracy: 44.73%Submissions: 152K+Points: 4
// Given the root of a binary tree and an integer k, count the number of downward-only paths where the sum of the node values in the path equals k.

// Note: A path can start and end at any node within the tree but must always move downward (from parent to child).

// Examples:

// Input: root = [8, 4, 5, 3, 2, N, 2, 3, -2, N, 1], k = 7

// Output: 3
// Explanation: The following paths sum to k
 
// /* Structure of Tree Node
// class Node {
//   public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };
// */
class Solution {
  public:
    void solve (Node* root, int k , vector<int> &path, int &count){
        if (root == NULL)
            return; 
        path.push_back(root->data); 
        solve (root -> left, k, path, count);
        solve (root -> right, k, path, count);
        int sum = 0 ;
        //now once the above 2 calls have ended we are at the end of a path. 
        //Here we need to check if the sum of the values in path == k
        //But note: since we can have paths starting from anywhere and ending anywhere
        //any contigous sequence of the path elements having sum = k counts as a path. 
        //eg:for test case 1 we have first path as [8,4,3,3]. We start from the end (the leaf node)
        //and see if we get any path == k. 3+4 = 7 =k so count ++. Going any further up gives sum > 7 so no need. 
        for (int i = path.size()-1; i>=0; i--){
            sum += path[i];
            if (sum == k)
                count ++; 
        }
        //Ok now we have processed the leaf node so we need to backtrack. SO we need to pop out the last element of the path as we are going backwards. 
        path.pop_back(); 
        return; 
    }
    int countAllPaths(Node *root, int k) {
        vector <int> path; //stores the current path we are on. 
        int count = 0 ; //number of paths with sum = k. 
        solve (root, k, path, count);
        return count; 
    }
};
//Above approach is o(n2) as for every node we are traversing the path vector which can be of size n.
//At each node, the loop goes through the current path.

// The maximum path length is the height H.

// So, roughly:

// N nodes
// ×
// up to H path elements checked per node

// Therefore:

// O(N × H)
/* Structure of Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
*/

class Solution {
  public:

    void solve(Node* root, int k, int currentSum,
               unordered_map<int, int>& mp, int& count) {

        // If there is no node, return
        if (root == NULL)
            return;

        // ---------------------------------------------------
        // STEP 1: Calculate prefix sum till current node
        // ---------------------------------------------------
        //
        // Example:
        //
        //       8
        //      /
        //     4
        //    /
        //   3
        //
        // At 8: currentSum = 8
        // At 4: currentSum = 8 + 4 = 12
        // At 3: currentSum = 8 + 4 + 3 = 15
        //
        currentSum += root->data;


        // ---------------------------------------------------
        // STEP 2: Find whether a path with sum k exists
        // ---------------------------------------------------
        //
        // Suppose:
        //
        // currentSum = 15
        // k = 7
        //
        // We want:
        //
        // Previous Prefix Sum + 7 = 15
        //
        // Therefore:
        //
        // Previous Prefix Sum = 15 - 7 = 8
        //
        // So we check whether prefix sum 8 existed before.
        //
        // If it existed, then:
        //
        // 15 - 8 = 7
        //
        // which means the nodes between those two points
        // form a path having sum k.
        //
        if (mp.find(currentSum - k) != mp.end()) {

            // mp[currentSum-k] tells us HOW MANY times
            // that prefix sum has occurred.
            //
            // Each occurrence represents one possible
            // starting point of a valid path.
            count += mp[currentSum - k];
        }


        // ---------------------------------------------------
        // STEP 3: Store the current prefix sum
        // ---------------------------------------------------
        //
        // Future nodes may need this prefix sum.
        //
        // Example:
        //
        // At node 8:
        // currentSum = 8
        //
        // We store:
        //
        // 8 -> 1
        //
        mp[currentSum]++;


        // ---------------------------------------------------
        // STEP 4: Explore left and right subtrees
        // ---------------------------------------------------

        solve(root->left, k, currentSum, mp, count);

        solve(root->right, k, currentSum, mp, count);


        // ---------------------------------------------------
        // STEP 5: BACKTRACK
        // ---------------------------------------------------
        //
        // We are done with this node's subtree.
        //
        // We must remove its prefix sum because when we
        // move to another branch, this prefix sum should
        // not be considered as part of that branch.
        //
        // This is similar to path.pop_back() in your
        // previous approach.
        //
        mp[currentSum]--;
    }


    int countAllPaths(Node* root, int k) {

        // HashMap:
        //
        // prefix sum -> number of times we have seen it
        //
        unordered_map<int, int> mp;


        // ---------------------------------------------------
        // IMPORTANT:
        // ---------------------------------------------------
        //
        // Prefix sum 0 exists BEFORE we start the tree.
        //
        // Suppose:
        //
        //       5
        //
        // k = 5
        //
        // currentSum = 5
        //
        // We calculate:
        //
        // currentSum - k
        // = 5 - 5
        // = 0
        //
        // So we need 0 to already exist in the map.
        //
        // This represents an "empty prefix" before the root.
        //
        mp[0] = 1;


        int count = 0;

        // Start DFS
        solve(root, k, 0, mp, count);

        return count;
    }
};