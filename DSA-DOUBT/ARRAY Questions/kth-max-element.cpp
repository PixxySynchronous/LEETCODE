// 215. Kth Largest Element in an Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
class Solution {
public:
    int partition (vector<int>& nums, int left, int right){
        int i = left; //i will be used to keep account of the last seen element which was smaller than the pivot. 
        int pivot = nums[right]; 
        for (int j = i; j<right ; j++){ //traversing the array and putting all elements less than the pivot to the left side of the array. 
            if (nums[j] < pivot){
                //this means we have found an element smaller than pivot, so we need to put it in nums[i], and then increase i by 1. 
                swap (nums[i], nums[j]);
                i++;
            }
            else 
                continue;  
        }
        //now i holds the correct position of the pivot. 
        swap (nums[i], nums[right]); 
        return i; 
    }
    int quicksort (vector<int>& nums, int left, int right,int k){
        if (left<=right){
            int pivotIndex = partition (nums, left, right); 
            if (pivotIndex == k ) return nums[pivotIndex]; 
            else if (pivotIndex > k) return quicksort (nums, left, pivotIndex-1, k); //Only search the left side. 
            else return quicksort (nums,pivotIndex+1, right, k); //Only search the right side. 
        }
        else 
            return 0; 
    }

    int findKthLargest(vector<int>& nums, int k) {
        //Can be done via quicksort, but instead of calling the 
        //quicksort function on both the left and the right arrays, we can be smart about it. 
        //We know after sorting the kth biggest element will appear in arr.size()-kth index. (Like second highest element would be second last element)
        //We also know that the pivot element is sorted.
        //If our pivot has landed at arr.size()-k index, then we got the answer, else we call quicksort acc. 
        int target = nums.size()-k; 
        int ans = quicksort(nums, 0, nums.size() -1 , target); 
        return ans; 

    }
};