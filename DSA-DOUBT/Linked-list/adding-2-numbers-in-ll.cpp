/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    public: 
    Node* revll (Node* head){
        if (head == NULL || head -> next == NULL)
        return head; 
        Node* curr = head; 
        Node* prev = NULL; 
        Node* next = NULL; 
        while (curr != NULL){
            next = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = next; 
        }
        return prev; 
    }
    
 
    Node* addTwoLists(Node* head1, Node* head2) {
        
        while (head1 -> data == 0  && head1 != NULL && head1 -> next != NULL){
            head1 = head1 -> next; 
        }
        while (head2 -> data == 0  && head2 != NULL && head2 -> next != NULL){
            head2 = head2 -> next; 
        }
        
        Node* ans= new Node (-1); 
        Node* anshead = ans; 
        Node* anstail = ans; 
        int carry = 0 ; 
        Node* curr1 = revll (head1); 
        Node* curr2 = revll (head2); 
        while (curr1 != NULL && curr2 != NULL){
            int sum = (curr1 -> data) + (curr2 -> data) + carry; 
            carry = sum / 10; 
            Node* digit = new Node (sum%10); 
            anstail -> next = digit; 
            anstail = digit; 
            curr1 = curr1 -> next;
            curr2 = curr2 -> next; 
        }
        while (curr1 != NULL){
            int sum = (curr1 -> data) + carry ; 
            carry = sum / 10;
            Node* digit = new Node (sum%10); 
            anstail -> next = digit; 
            anstail = digit; 
            curr1 = curr1 -> next;
            
        }
         while (curr2 != NULL){
            int sum = (curr2 -> data) + carry ; 
            carry = sum / 10;
            Node* digit = new Node (sum%10); 
            anstail -> next = digit; 
            anstail = digit; 
            curr2 = curr2 -> next;
        }
        if (carry != 0 ){
            Node* digit = new Node (carry); 
            anstail -> next = digit; 
            anstail = digit; 
        }
        
        
        return revll (anshead -> next); 
        
        
    }
};

//I could think of reversing the linked lists and adding them. 
//Logic is simple. Reverse both linked lists, add corresponding digits and maintain carry.
//Finally reverse the resultant linked list and return. 