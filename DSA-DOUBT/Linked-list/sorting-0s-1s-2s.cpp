// Problem statement
// Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.



// Example:
// Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
// The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    Node* zerohead = new Node (-1); 
    Node* onehead = new Node (-1); 
    Node* twohead = new Node (-1); 
    Node* zerotail = zerohead;
    Node* onetail = onehead; 
    Node* twotail = twohead; 

    Node* curr = head; 
    while (curr != NULL){
        if (curr->data == 0){
            zerotail->next = curr; 
            zerotail = curr; 
        }
        if (curr->data == 1){
            onetail->next = curr; 
            onetail = curr; 
        }
        if (curr->data == 2){
            twotail->next = curr; 
            twotail = curr; 
        }
        curr = curr -> next; 
    }
    if (onehead -> next != NULL )
        zerotail -> next = onehead -> next; 
    else
        zerotail -> next = twohead -> next; 

    onetail -> next = twohead -> next ; 
    twotail -> next = NULL ; 
    return zerohead -> next; 


}

//Approach: Create 3 separate lists for 0s, 1s and 2s. Finally connect them.
// DUmmy nodes are used to simplify the code for edge cases where any of the lists may be empty.
// TC: O(N) , SC: O(1)