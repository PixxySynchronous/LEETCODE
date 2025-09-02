// Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.

// Note:
// 1. If the list is empty, the function immediately returns None because there is no middle node to find.
// 2. If the list has only one node, then the only node in the list is trivially the middle node, and the function returns that node.

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

Node *findMiddle(Node *head) {
    Node *curr = head; 
    Node *middle = head ; 
    while (curr != NULL && curr -> next !=NULL ){
        //The above while loop ensures that current can move by 2 steps by ensuring that the next value is 
        // not null. If we are on the second last element, current moving by 2 steps makes it pointing to
        //null and hence the loop wont go again. 
        middle = middle->next;
        curr = curr->next->next;  
    }
    return middle; 
}
    

//Initial approach was to count the elements and then take out the half, but this is more ooptimised even though same time complextity of O(n) since we are traversing the array once. 