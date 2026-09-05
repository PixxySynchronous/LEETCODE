// Reverse first K of a Queue
// Difficulty: EasyAccuracy: 81.28%Submissions: 177K+Points: 2
// Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if ( k > q.size())
        return q;
        stack <int> s; 
        int n = q.size(); 
        for (int i = 0 ; i < k ; i++){ //push the first k elements into a stack.
            s.push(q.front()); 
            q.pop(); 
        }
        while (!s.empty()){ //pop the elements from the stack and push them back into the queue. This will reverse the order of the first k elements.
            // this results in the first k elements being reversed and the rest of the elements being in the same order as before.
            q.push(s.top());
            s.pop(); 
        }
        for ( int i =0 ; i<n-k; i++){ // push the remaining elements of the queue to the back of the queue. This will maintain the order of the remaining elements.
            q.push(q.front()); 
            q.pop(); 
        }
        return q; 
    }
        
    
};
// Reverse k elements. Put them in back of queue. Put the elems in front at the back. 
// tc is o(n) sc is o(k)