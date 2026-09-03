// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
// Example 3:

// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7; 
        int ans = 0; 
        sort ( nums.begin(), nums.end()); 
        int i = 0 ; 
        int j = nums.size() - 1; 
        //precompute powers of 2. Use of 2LL makes sure multiplication happens in long long to prevent overflow.
        vector<int> powers (nums.size()); 
        powers[0] = 1; 
        for (int k = 1; k<nums.size() ; k++){
            powers[k] = (2LL * powers[k-1]) % mod; //2^k = 2^k-1 * 2 
            //powers[k] = 2^k. 
        }
        while (i<=j){
            if (nums[i] + nums[j] <= target){ //if the last 2 elements are valid, all possible combinations of elements in the between is also valid, meaning 2^(j-i)
                ans = (ans + powers[j-i])%mod; 
                i++; 
            }
            else 
                j--;
        }
        return ans; 
    }
};