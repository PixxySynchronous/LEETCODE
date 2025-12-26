// You are given a linked list of N nodes. Your task is to 
// remove the duplicate nodes from the linked list such that every element in the 
// linked list occurs only once i.e. in case an element occurs more than once, only keep its first occurrence in the list.

// For example :
// Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.

// Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.
#include <bits/stdc++.h> 
#include <map>
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{   if (head == NULL || head -> next == NULL)
    return head; 
    unordered_map <int, bool> visited; 
    Node* curr = head; 
    visited[curr->data] = true;  
    while (curr->next != NULL ){
        if (visited[curr->next->data] == true ){
            Node* todelete = curr->next; 
            curr -> next = curr -> next ->next;
            delete todelete;  
        }
        else{
        curr = curr -> next; 
        visited[curr -> data] = true;
        }
    }
    return head; 

}

//We must only move current if node has not been deleted. If we move current every time, we will skip nodes after deletion.
//Using unordered_map to store visited nodes for O(1) access time. Maps give TLE here.