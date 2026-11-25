// 2831. Find the Longest Equal Subarray
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array nums and an integer k.

// A subarray is called equal if all of its elements are equal. Note that the empty subarray is an equal subarray.

// Return the length of the longest possible equal subarray after deleting at most k elements from nums.

// A subarray is a contiguous, possibly empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,3,2,3,1,3], k = 3
// Output: 3
// Explanation: It's optimal to delete the elements at index 2 and index 4.
// After deleting them, nums becomes equal to [1, 3, 3, 3].
// The longest equal subarray starts at i = 1 and ends at j = 3 with length equal to 3.
// It can be proven that no longer equal subarrays can be created.
// Example 2:

// Input: nums = [1,1,2,2,1,1], k = 2
// Output: 4
// Explanation: It's optimal to delete the elements at index 2 and index 3.
// After deleting them, nums becomes equal to [1, 1, 1, 1].
// The array itself is an equal subarray, so the answer is 4.
// It can be proven that no longer equal subarrays can be created.
class Solution {

public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        // basic approach same as https://leetcode.com/problems/longest-repeating-character-replacement/description/
        int left = 0; 
        int right = 0 ; 
        int maxFreq = 0 ; 
        int ans = 0 ; 
        unordered_map <int,int> mp; 
        while (right<nums.size()){
            mp[nums[right]]++; 
            maxFreq = max (maxFreq,mp[nums[right]]);
            if (right-left+1 - maxFreq <= k){
                //valid window. 
                // I retrun maxfreq instead of the size of the window because the size of the window is not left - right + 1 its that - the number of deletions required in that window. I would need to keep track of those deletions and how many are required in the window which I dont want to do, but I know after how many deletions the siz ewould just equal to the maxfreq the window has. we use maxfreq as it would represent the window with the biggest size. 
                ans = max (ans, maxFreq); 
            }
            else{
                //invalid window
                while (right - left + 1 - maxFreq >k){
                    mp[nums[left]] --; 
                    left ++; 
                }
            }
            right ++; 
        }
        return ans; 
    }
};