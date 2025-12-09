// You are given the head of a linked list containing integers, You need to find out whether the given linked list is circular or not.

// Note :

// 1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.
// 2. An empty linked will also be considered as circular.
// 3. All the integers in the linked list are unique.
// 4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.

#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    //the following only works if the circular loop starts with the head and not in between
    //as the logic is the current value will either end up as head or its next value will be null. 

    if (head == NULL)
    return true; 
    // Node* curr = head->next; 
    // while (curr!=NULL && curr != head){
    //     curr=curr->next; 
    // }
    // return (curr==head); 
    //Floyds cycle algorithm : run 2 pointers fast and slow. If loop present, they will eventually be equal to each other
    //else fast becomes null. 
    Node* fast = head; 
    Node* slow = head;
    while (fast!=NULL && fast->next!=NULL){
        fast= fast->next->next;
        slow= slow->next;
        if (fast==slow)
        if (fast==head) //since this qsn only considers it a loop if looping is from head. 
        return true; 
        else
        return false; 
        
    }
    return false; 
}
