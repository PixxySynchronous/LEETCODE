// 152. Maximum Product Subarray
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0

// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // I can get max product by either multiplying a positive number with the current max Product. 
        // Or multiplying a negative number by multiplying it with the current min preoduct. 
        // So for each window I need to update both.  
        int i = 1 ; 
        int currMax = nums[0]; //max Product upto that point 
        int currMin = nums[0]; //min product upto that point 
        int ans = nums[0]; 

        while (i<nums.size()){
            // while iterating through the array, we maintain the 2 products. 
            //currMax and currMin. 
            //currMax (nums[i], nums[i]*currMax, nums[i]*currMin)
            //notice how either currMax EXTENDS the previous subarray or starts a new one. 
            //similarly 
            // currMin min(nums[i], nums[i]*currMax, nums[i]*currMin); 
            //currMin also either extends a window, or starts a new window.  
            // for example 2,3,-2,4
            //     at i = 0 both max and min = 2
            //     at i = 1 max = 6, min = 3 (new window) 
            // Note how at index i, we need the currmax and currmin of index i-1 to calculate the new currs, 
            // To retain the old currs, we cant overwrite in them and so we need to make new variables first and then equate them to it. 
            int newMax = max (nums[i], nums[i]*currMax);
            newMax = max (newMax, nums[i]*currMin);
            int newMin = min (nums[i], nums[i]*currMax);
            newMin = min (newMin,nums[i]*currMin);
            currMax = newMax; 
            currMin = newMin; 
            //currMax represents the current maximum product, not the maxproduct yet encountered. We store that in ans. 
            ans = max (ans, currMax); 
            i++; 
        }
        return ans; 
    }
};