// Problem statement
// You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

// Note:

// The given linked lists may or may not be null.
// For example:

// If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

// The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* Sorted = new  Node<int> (-1);
    Node<int>* Sortedtail = Sorted;  
    Node<int>* p1 = first; 
    Node<int>* p2 = second; 
    while (p1 != NULL && p2 != NULL){
        if (p1->data <= p2 -> data){
            Sortedtail -> next = p1; 
            Sortedtail = p1;
            p1 = p1 -> next; 
        }
        else{
            Sortedtail -> next = p2 ; 
            Sortedtail = p2; 
            p2 = p2 -> next; 
        } 
    }
    if (p1 != NULL){
        while (p1 != NULL){
            Sortedtail -> next = p1;
            Sortedtail = p1; 
            p1 = p1 -> next; 
        }
    }
    else {
        while (p2 != NULL){
            Sortedtail -> next = p2 ; 
            Sortedtail = p2; 
            p2 = p2 -> next; 

        }
    }
    return Sorted->next; 
}
//TC: O(N+M) , SC: O(1)
//Approach: Use two pointers to traverse both lists and compare the current nodes.
// Append the smaller node to the sorted list and move the pointer forward.