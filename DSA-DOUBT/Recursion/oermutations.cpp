// LEETCODE 46 Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 class Solution {
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, int index){
        if (index>=nums.size()){
            ans.push_back(output);
            return;
        }
        for (int i= index; i<nums.size(); i++){
            //so basically if {1,2,3} then first we take 1 and move on to make 1,2,3 by including all
            //then we swap 2 and 3 etc al.
            swap(nums[index], nums[i]);
            output.push_back (nums[index]);
            solve (nums,ans,output,index+1); 
            output.pop_back(); 
            swap (nums[index], nums[i]); // swapped again as when we backtrack we need the original string with us .
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> output; 
        int index= 0 ; 
        solve (nums, ans, output, index);
        return ans; 
        
    }
};