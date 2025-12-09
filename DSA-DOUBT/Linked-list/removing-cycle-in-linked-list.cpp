// Problem statement
// Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.

// Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.

// Detailed explanation ( Input/output format, Notes, Images )

/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
//The below function works on the floyds cycle detection algorithm. Cycle is present if fast==slow.
//TO find the starting node of the cycle, once slow==fast, reset slow at head and increment both by 1 till they meet
//at the start of the loop. 
Node* loopDetected(Node* head){
    Node* fast =head;
    Node* slow = head; 
    while ( fast !=NULL && fast->next !=NULL){
        fast=fast->next->next;
        slow=slow->next; 
        if (fast==slow){
            slow =head;
            while (fast!=slow){
                fast=fast->next;
                slow=slow->next; 
            }
            return slow; 
        }
        
    }
    return NULL; 
}
//To remove the loop , the above function gives back the index of the starting of the loop. We then create temp
//from starting of the loop till it reaches the ned of the loop, and then make temp->next as NULL to break the loop. 
Node *removeLoop(Node *head)
{
   if (head == NULL)
   return head; 
        Node* slow = loopDetected(head);
        if (slow==NULL)
        return head; 
        Node* temp = slow; 
        while (temp->next != slow){
            temp=temp->next; 
        }
        temp->next = NULL;


   
   return head; 
}