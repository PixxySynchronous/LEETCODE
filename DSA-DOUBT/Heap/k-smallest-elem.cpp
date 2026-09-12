class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq; //max heap.
        //approach is that if we maintain a max heap of k smallest elements, 
        //then the root or the top of that tree will contain the largest element
        //amongst them. SO heap is a heap of the k smallest elements, and its top is the largest amongsth them, 
        //making it the kth smallest element. 
        for (int x : arr){
            pq.push(x); 
            if (pq.size() > k)
                pq.pop(); //biggest element is taken out as it is not in the k smallest elements list. 
        }
        return pq.top(); 
    }
};
//Since pushing and popping from a heap takes logk time (for a heap of size k), and we are doing it n times, the time complexity is O(nlogk).
//as the heap is of size k, the space complexity is O(k).