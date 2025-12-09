// Problem statement
// Given a singly linked list of integers. Your task is to return the head of the reversed linked list.

// For example:
// The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 

{   //If only one element or no element:
    if (head == NULL || head->next ==NULL)
    return head; 
    LinkedListNode<int> *curr = head ; 
    LinkedListNode<int> *prev = NULL; 
    LinkedListNode<int> *forward =NULL; 
    //current points to the current element in check, previous points to the element before that, and forward points to the element afterwards. Curr ka next is set to prev to reverse the link list. To make sure that rest of the list is not lost (as curr->next is now pointing to the prev element not the next element) we first make a forward poointer point to the next element. RUnning through the loop  at the end, curr will be null ,(1 next to the last element), and prev will point to the last element which will now become the new head of the ll. 
    while (curr!=NULL){
        forward = curr -> next; 
        curr -> next = prev;
        prev = curr ; 
        curr = forward; 

    }
    head = prev; 
    return head;
    
}