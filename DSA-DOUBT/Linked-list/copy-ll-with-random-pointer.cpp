// 138. Copy List with Random Pointer
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

 

// Example 1:


// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Below approach is o(n) space and time. 
        // We simply make a map of original nodes and their copies and then join the pointers using it
        unordered_map <Node*, Node*> mp; // original : copy
        Node* curr = head; 
        while ( curr != NULL){
            mp[curr] = new Node (curr -> val); 
            curr = curr -> next; 
        }
        curr = head;
        while (curr != NULL){
            //mp[curr] has value of the copied node. mp[curr] -> next means copied nodes' next.
            //mp[curr -> next] has value of curr -> next's copy. 
            //this is why below syntax makes the deep copy. 
            mp[curr] -> next = mp[curr->next]; 
            mp[curr] -> random = mp [curr -> random];
            curr = curr -> next; 
        }
        return mp[head]; 
        
        // A better approach is having the copy of a node be its next value. 
        // eg nodeA -> next = nodeA copy 
        // This allows us to do the above but without the xtra space. 
    
 

    }
};