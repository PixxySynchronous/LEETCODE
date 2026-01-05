/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* revll (Node* head){
        Node* curr = head; 
        Node* prev = NULL; 
        while (curr != NULL ){
            Node* next = curr -> next; 
            curr-> next = prev;  
            prev = curr; 
            curr = next; 
        }
        return prev ; 
    }
    
    Node* findmid (Node* head){
        Node* curr = head; 
        Node* fast = curr; 
        Node* slow = curr; 
        while (fast != NULL && fast->next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next; 
            slow = slow -> next; 
        }
        return slow; 
    }
    
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL)
            return true;
        Node* curr = head; 
        Node* mid = findmid (curr); 
        mid->next = revll (mid -> next); 
        Node* p1 = mid -> next; 
        while (p1 != NULL){
            if (curr -> data != p1 -> data)
            return false; 
            else{
                curr = curr -> next; 
                p1 = p1 -> next; 
            }
        }
        mid -> next = revll (mid -> next); 
        return true; 
       
        }
};
// I couldnt think of this approach myself. But the approach of putting the 
//data of the linked list into an array and checking if the array is palindrome came to my mind.
//Approach: Find mid of linked list using slow and fast pointer technique. Reverse the second half of the linked list
//Compare first half and reversed second half node by node. If all nodes match, it is a palindrome. Finally, reverse the second half again to restore original list.