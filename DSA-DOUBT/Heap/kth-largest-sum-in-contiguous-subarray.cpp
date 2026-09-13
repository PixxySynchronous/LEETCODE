// K-th Largest Sum Contiguous Subarray
// Solved
// Difficulty: MediumAccuracy: 54.33%Submissions: 43K+Points: 4Average Time: 20m
// Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.

// Examples:

// Input: arr[] = [3, 2, 1], k = 2 
// Output: 5
// Explanation: The different subarray sums we can get from the array are = [6, 5, 3, 2, 1]. Where 5 is the 2nd largest.
// Input: arr[] = [2, 6, 4, 1], k = 3
// Output: 11
// Explanation: The different subarray sums we can get from the arrayare = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.
// Constraints:
// 1 <= arr.size() <= 1000
// 1 <= k <= (n*(n+1))/2
// -105 <= arr[i] <= 105


class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // step 1 is to find all contiguous subarrays. 
        // if an array is [1,2,3] its contiguous subarrs are 
        // 1   1,2.  1,2,3.   2.   2,3
        // Notice this can be done via a nested for loop. 
        
        // step 2 is to calculate and store the sums of these subarrays. 
        // One approach would be to store them into a separate vector, sort the vector,
        // and then return the size-kth index of the vector. However this is sc o(n2) as 
        // vector will have sums of all subarrays which are n2 so vector size will be n2. 
        // Best approach is to push the sums in a min heap. 
        // If size of minHeap gets bigger than k, pop the top if the curr sum is bigger than it. 
        // This will result in a heap of the k biggest elemnts (sums) and the top of the heap would 
        // be the smallest of those i.e kth largest sum. 
        priority_queue<int, vector<int>, greater<int>> pq; 
        for (int i = 0 ; i<arr.size() ;i++){
            int sum = 0; //above loop signals the start of a new start of a subarray. 
            // for each j, sum just becomes sum+=arr[j] so to store sums of all subarrays we just 
            // need to push sum in each iteration of j. 
            for (int j = i; j<arr.size();j++){
                sum+=arr[j]; 
                if (pq.size()<k)
                    pq.push(sum); 
                else{
                    if (pq.top() < sum){
                        pq.pop(); 
                        pq.push(sum); 
                    }
                    else 
                        continue; 
                }
            }
        }
        return pq.top(); 
        
    }
};
// TC: O(n^2 log k)
// There are O(n^2) contiguous subarrays.
// For every subarray, we may perform push/pop on a min heap
// of size at most k, and each heap operation costs O(log k).
// Therefore: O(n^2 * log k).
// sc: O(k) for the min heap of size k.