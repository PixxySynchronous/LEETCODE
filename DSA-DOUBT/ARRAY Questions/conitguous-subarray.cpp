// 2913. Subarrays Distinct Element Sum of Squares I
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array nums.

// The distinct count of a subarray of nums is defined as:

// Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
// Return the sum of the squares of distinct counts of all subarrays of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,2,1]
// Output: 15
// Explanation: Six possible subarrays are:
// [1]: 1 distinct value
// [2]: 1 distinct value
// [1]: 1 distinct value
// [1,2]: 2 distinct values
// [2,1]: 2 distinct values
// [1,2,1]: 2 distinct values
// The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int> st; 
        int ans = 0;
        for (int i = 0; i<nums.size();i++){
            int distinct = 0; 
            st.clear(); 
            for (int j = i; j<nums.size();j++){
                if (st.find(nums[j]) == st.end()){
                    distinct++; 
                    st.insert(nums[j]); 
                }
                 ans += (distinct*distinct); 
                // every iteration of the j loop generates a subseq. 
            }
           
        }
        return ans; 
    }
};