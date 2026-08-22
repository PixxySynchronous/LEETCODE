// 45. Jump Game II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()==1) return 0; 
        //we start at index 0. 
        //What the approach here is, we have a range of indexes we can jump to, [1-arr[0]]. 
        //We choose the index which will extend our range the most. 
        int currRange = 0; //Since we havent processed any element, current range is 0. 
        int furthestRange = 0 ;
        int endOfRange = 0; //end of the range we are trying to find the furthest range extension from. 
        int jumps = 0;  
        for (int i=0; i<nums.size() ; i++){
            //This for loop is used to traverse within the range of the index. 
            //eg) if arr[0] = 2, this for loop first finds the furthest jump we can make within that range. 
            furthestRange = max (furthestRange, nums[i]+i); 
            if (i==endOfRange){ //we have processed the current range, so we move on to the next range (by jumping). Which would be = furthestRange of previous scan. 
                jumps++;
                endOfRange = furthestRange; 
                if (endOfRange >= nums.size()-1) //we can reach the end with the current number jumps. 
                    break;
            }
        }
        return jumps; 

    }
};