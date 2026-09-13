class Solution {
public:
    // int partition (vector<int>& nums, int left, int right){
    //     int i = left; //i will be used to keep account of the last seen element which was smaller than the pivot. 
    //     int pivot = nums[right]; 
    //     for (int j = i; j<right ; j++){ //traversing the array and putting all elements less than the pivot to the left side of the array. 
    //         if (nums[j] < pivot){
    //             //this means we have found an element smaller than pivot, so we need to put it in nums[i], and then increase i by 1. 
    //             swap (nums[i], nums[j]);
    //             i++;
    //         }
    //         else 
    //             continue;  
    //     }
    //     //now i holds the correct position of the pivot. 
    //     swap (nums[i], nums[right]); 
    //     return i; 
    // }
    // int quicksort (vector<int>& nums, int left, int right,int k){
    //     if (left<=right){
    //         int pivotIndex = partition (nums, left, right); 
    //         if (pivotIndex == k ) return nums[pivotIndex]; 
    //         else if (pivotIndex > k) return quicksort (nums, left, pivotIndex-1, k); //Only search the left side. 
    //         else return quicksort (nums,pivotIndex+1, right, k); //Only search the right side. 
    //     }
    //     else 
    //         return 0; 
    // }

    int findKthLargest(vector<int>& nums, int k) {
    //     //Can be done via quicksort, but instead of calling the 
    //     //quicksort function on both the left and the right arrays, we can be smart about it. 
    //     //We know after sorting the kth biggest element will appear in arr.size()-kth index. (Like second highest element would be second last element)
    //     //We also know that the pivot element is sorted.
    //     //If our pivot has landed at arr.size()-k index, then we got the answer, else we call quicksort acc. 
    //     int target = nums.size()-k; 
    //     int ans = quicksort(nums, 0, nums.size() -1 , target); 
    //     return ans; 

    // }
    //Can also be done via priority queue. Priority queue maintains a heap. If we maintain a min heap of size k, the top most element will have the kth biggest element. 
    priority_queue<int, vector<int>, greater<int>> pq; //a min heap is required. 
    //This is because we want the kth Largest element. So we want to keep the biggest k elements in the heap. And the top of this heap would be the smallest amongst them (as it is a min heap), so we return that. 
    for (int x: nums){
        pq.push(x); 
        if (pq.size() > k)
            pq.pop(); //automatically pops the current smallest element (we need the k biggest elements in the heap)
    }
    return pq.top(); 
    }
};