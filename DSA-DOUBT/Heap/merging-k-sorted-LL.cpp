// 23. Merge k Sorted Lists
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct compare {
    public:
        bool operator ()(ListNode* a, ListNode* b){
            return a->val > b->val; 
        }          
}; 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // We can insert all elements into a array and then sort it and then make a ll and return it. 
        // But that would be ineffecient compared to the minHeap method. (Look at k sorted arrays qsn for more explanation). 
        // One difference here is we dont need to think which LL to increment (i.e store which LL the top of the heap is part of) because we can simply do push(top-> next). 
        
        //Step 1: insert the first elements of all k lists in min heap. 
        //Each element is a head of a diff linked list. I need to put all heads in the min heap. 
        priority_queue<ListNode*, vector<ListNode*>, compare> pq; 
        for (int i = 0 ; i<lists.size(); i++){
            //Since according to constraints list[i] can be equal to 0, i.e NULL we can put an if condition to check that 
            if (lists[i] != NULL)
                pq.push(lists[i]); 
        }

        //Step 2: make head and tail of ans LL. 
        ListNode* ansHead = NULL; 
        ListNode* ansTail = NULL; 

        //Step 3: keep popping, inserting into ans and pushing till queue is empty. 
        while (!pq.empty()){
            ListNode* top = pq.top(); 
            pq.pop(); 
            if (ansHead == NULL){
                //this is the first element of the ans LL 
                ansHead = top; 
                ansTail = top; 
            }
            else{
                //if it is not the first element, then just append it to the end of the list. 
                ansTail -> next = top; 
                ansTail = ansTail -> next; 
            }
            // we have popped and inserted into ans now we need to push
            if (top ->next != NULL)
                pq.push(top->next); 
        }
        return ansHead; 
    }
    
};