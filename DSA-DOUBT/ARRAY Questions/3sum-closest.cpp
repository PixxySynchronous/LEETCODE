// 16. 3Sum Closest
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array nums of length n and an integer target.

// Find three integers at distinct indices in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // I am thinking of 3 sum but instead of writing down the triplets with the sum = target,
        // I just write down the triplets which have the abs difference from the target as least.
        int diff = INT_MAX; 
        int ans; 
        sort(nums.begin(), nums.end()); 
        for (int i = 0 ; i<nums.size() - 1; i++){
            int a = nums[i]; 
            int left = i+1; 
            int right = nums.size()-1; 
            while (left<right){
                int sum = a + nums[left] + nums[right]; 
                if (abs(sum-target) < diff){
                    diff = abs(sum-target); 
                    ans = sum; 
                }
                if (sum > target)
                    right --; 
                if (sum < target) 
                    left ++;  
                if (sum == target) 
                    return sum; 

            }
        }
        return ans; 
    }
};