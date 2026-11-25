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
    // One approach is to rev ll then rev first k nodes and then remaining nodes.
    // simpler approach is to connect the last node to first noe to make list circular and then disconnect the list at size-kth node. 

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL || k== 0)
            return head; 
        ListNode* curr = head;
        int size = 1; 
        while (curr -> next != NULL){
            size ++; 
            curr = curr -> next; 
        }
        k = k%size; 
        curr -> next = head; //connects last node to first. 
        int node = 0 ; 
        while (node != size - k){
            curr = curr -> next; //traveling to the goal node. 
            node++; 
        }
        head = curr -> next; // itll be the start of the new LL. 
        curr -> next = NULL; //disconnect circularity
        return head; 
    }
};