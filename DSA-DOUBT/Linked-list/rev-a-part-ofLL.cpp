// 92. Reverse Linked List II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]
 



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
    ListNode* revLL (ListNode* head, int number){
        //APproach is to save the left part and the right part. rev the middle and reconnect both. 
        if (head == NULL || head -> next == NULL)
            return head; 
        ListNode* curr = head;
        ListNode* next = NULL; 
        ListNode* prev = NULL; 
        while (number > 0){
            next = curr -> next;
            curr -> next = prev; 
            prev = curr; 
            curr = next; 
            number --; 
        }
        return prev; 
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head -> next == NULL)
            return head; 
        
        if (left == right)
            return head;
        
        int startCounter = 1; 
        ListNode* leftPart;  // needs to point to the node right before the ndoe which is the start of the revLL. 
        // if left ==1 no such node exists so we jsut make a dummy node to act the same. 
        if (left == 1){
            leftPart = new ListNode(-1); 
            leftPart -> next = head; 
        }
            
        if (left > 1){
                leftPart = head;
                while (startCounter != left -1 || left == 1){
                leftPart = leftPart -> next; 
                startCounter++;
            }
        }
       
        //Now left part -> next points to the start of the LL which needs to be rev. 
        ListNode* revStart = leftPart -> next; 
        int endCounter = 1; 
        ListNode* rightPart = head; 
        while (endCounter != right){
            rightPart = rightPart -> next; 
            endCounter ++;
        }
        ListNode* endPart = rightPart -> next; //saves the linked list after the last node which got reversed. 
        int nodesToReverse = right - left + 1; 
        leftPart -> next = revLL (leftPart -> next,  nodesToReverse); 
        // after reversal the revStart pointing to the start of the node which needed to be rev is now at the end of the rev LL. 
        revStart -> next = endPart; //attach the part after the revLL
        if (left == 1)
            return leftPart -> next; //dummy node ke next wala is head. 
        
        return head; 

        
    }
};