//Leetcode 78 Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

class Solution {
void sums (vector<int>& nums , vector <int> &output, int index, vector <vector <int>> &ans ){
    if (index>=nums.size()){
        ans.push_back(output);
        return; 
    }
    //exclude the element 
    sums (nums, output, index+1, ans);
    //include the element 
    int element = nums [index]; 
    output.push_back(element); 
    sums (nums, output, index+1, ans); 
    //backtrack
    output.pop_back();
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector <int> output; 
        int index= 0; 
        sums (nums, output, index, ans); 
        return ans; 
    }
};
//this answer makes a state space tree of backtracking where in basically we make 2 branches of either
//including the element or excluding the element and then backtracking. 