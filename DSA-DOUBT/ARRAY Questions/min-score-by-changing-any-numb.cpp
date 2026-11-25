// 2567. Minimum Score by Changing Two Elements
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums.

// The low score of nums is the minimum absolute difference between any two integers.
// The high score of nums is the maximum absolute difference between any two integers.
// The score of nums is the sum of the high and low scores.
// Return the minimum score after changing two elements of nums.

 

// Example 1:

// Input: nums = [1,4,7,8,5]

// Output: 3

// Explanation:

// Change nums[0] and nums[1] to be 6 so that nums becomes [6,6,7,8,5].
// The low score is the minimum absolute difference: |6 - 6| = 0.
// The high score is the maximum absolute difference: |8 - 5| = 3.
// The sum of high and low score is 3.
// Example 2:

// Input: nums = [1,4,3]

// Output: 0

// Explanation:

// Change nums[1] and nums[2] to 1 so that nums becomes [1,1,1].
// The sum of maximum absolute difference and minimum absolute difference is 0.
 

// Constraints:

// 3 <= nums.length <= 105
// 1 <= nums[i] <= 109
 
// Seen this question in a real interview before?
// 1/6
// Yes
// No
// Accepted
// 83,521/127.3K
// Acceptance Rate
// 65.6%

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort (nums.begin(), nums.end()); 
        // We can make 2 numbers change, so this means we have 3 valuable cases, 
        // changing the biggedt 2 elements -> we will make thenm equal to the third biggest element because if it is smaller than that then the biggest element changes and hence our swithced out numbers wont even be used in the score calculations. 
        // similar logic for al;l 3 cases: 
        
        // case 1 is i change the last 2 elemen ts equal to the third last element (nums[nums.size()-3]).
        // case 2 is I change the first 2 elements equal to the third element 
        // case 3 is I change the first element as the second element and the last element as the second last element. 
        // Instead of actually changing the numbers I can just use indices of those numbers that I am going to rteplace the numbers with. 
        // in the  3 cases, the min difference becomes 0 so the score becomes max difference.
        int n = nums.size(); 
        return min (nums[n-3]-nums[0], min (nums[n-1] - nums[2], nums[n-2]-nums[1]));  
    }
};