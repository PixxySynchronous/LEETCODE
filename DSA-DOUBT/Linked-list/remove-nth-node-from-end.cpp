// Remove Nth Node From End of List
// Medium
// Topics
// Company Tags
// Hints
// Given the head of a linked list and an integer n, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4], n = 2

// Output: [1,2,4]
// Example 2:

// Input: head = [5], n = 1

// Output: []
// Example 3:

// Input: head = [1,2], n = 2

// Output: [2]
// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //count the size of the LL
        //do size - n traversals. 
        //remove the next node.
        if (head == NULL) return head; 
        ListNode* tail = head; 
        int size = 1; 
        while (tail -> next != NULL){
            tail = tail -> next; 
            size++; //by the end of the loop i get the size of the LL. 
        }
        ListNode* dummy = new ListNode (0); 
        dummy = head; //this is done in order to deal with the cases wherein the head
        //node itself needs to be deleted. SO we equate dummy = head and then return dummy -> next, i.e head -> next. 
        if (size == n) return dummy -> next;
        int counter = 1; 
        ListNode* curr = head; 
        while (counter != size - n){
            curr = curr -> next; 
            counter ++; 
        } //this puts current right behind the target node. 
        if (curr -> next != NULL)
            curr -> next = curr -> next -> next; 
        return head; 

    }
    //There is another approach of having 2 pointers. Move one pointer n positions in front, and then 
    //move the other pointer and the fast pointer by 1 till fast pointer reaches the end. 
    //once thats done, the left pointer's next is the node to delete.
    //this allows the solution to be found in one pass. 
    //return dummy->next.
};
