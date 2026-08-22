// 2807. Insert Greatest Common Divisors in Linked List
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a linked list head, in which each node contains an integer value.

// Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

// Return the linked list after insertion.

// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 

// Example 1:


// Input: head = [18,6,10,3]
// Output: [18,6,6,2,10,1,3]
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
    int gcd (int a,int b){
        //gcd of two numbers can be found in o(log(min(a,b))).
        //This can be done via the following loop.
        //Remainder = a%b
        //a=b and then b= remainder. 
        //Run this loop till b is 0, then a will have the ans. 
        while (b!=0){
            int rem = a%b;
            a=b;
            b=rem; 
        }
        return a; 
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head; 
        while (curr!= NULL && curr -> next != NULL){
            int a = curr ->val; 
            int b = curr->next->val; 
            int data = gcd(a,b);
            ListNode* temp = new ListNode(data); 
            temp -> next = curr -> next; 
            curr -> next = temp; 
            curr = curr -> next -> next; 
        }
        return head; 
    }
};