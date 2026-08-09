// Reorder Linked List
// Medium
// Topics
// Company Tags
// Hints
// You are given the head of a singly linked-list.

// The positions of a linked list of length = 7 for example, can intially be represented as:

// [0, 1, 2, 3, 4, 5, 6]

// Reorder the nodes of the linked list to be in the following order:

// [0, 6, 1, 5, 2, 4, 3]

// Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

// [0, n-1, 1, n-2, 2, n-3, ...]

// You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.

// Example 1:

// Input: head = [2,4,6,8]

// Output: [2,8,4,6]
// Example 2:

// Input: head = [2,4,6,8,10]

// Output: [2,10,4,8,6]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* revLL (ListNode* mid){
        ListNode* curr = mid;
        ListNode* prev = NULL;
        ListNode* frwd = NULL;
        while (curr!= NULL){
            frwd = curr -> next; 
            curr -> next = prev;
            prev = curr; 
            curr = frwd; 
        }
        return prev; 
    }
    void reorderList(ListNode* head) {
        //Need to reach the middle of the list, then reverse the second half. 
        ListNode* slow = head; 
        ListNode* fast = head; 
        while (fast -> next!= NULL && fast->next -> next !=NULL){ //we want the lower value of mid for even length strings. 
            slow = slow->next; 
            fast = fast -> next -> next; 
        }
        ListNode* p2 = revLL(slow->next); 
        slow -> next = NULL; //we need to split the list down the middle
        ListNode* p1 = head; 
        ListNode* p2next = NULL;
        ListNode* p1next = NULL;
        while (p2 != NULL){
            p2next = p2 -> next; 
            p1next = p1 -> next;
            p1  -> next = p2; 
            p2 -> next = p1next; 
            p1 = p1next;
            p2 = p2next; 
        } //Save the pointers' next. Make the pointers next of each other, and then move the pointers. 

    }
};
