// You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.



// Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.



// For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.



// Implement a function that performs this reversal, and returns the head of the modified linked list.



// Example:
// Input: 'list' = [1, 2, 3, 4], 'k' = 2

// Output: 2 1 4 3

// Explanation:
// We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2 elements then the next 2 elements, giving us 2->1->4->3.


/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    if (head==NULL)
    return NULL; 
    Node *curr = head; 
    Node *forward = NULL; 
    Node* prev = NULL; 
    int count = 0; 
    //reverse first k bits. This would result in head being at the end of the rev sub link list therfore 
    // head-> next will point to the remaining list. 
    while (count < k && curr !=NULL ){
        forward = curr -> next; 
        curr-> next = prev;
        prev = curr; 
        curr= forward; 
        count ++ ; 
    }
    if (forward!=NULL)
    head->next = kReverse(forward, k) ;
    return prev; 

}

//Logic from video, wrote the code myself . 