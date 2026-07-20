Top K Frequent Elements
Medium
Topics
Company Tags
Hints
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]
Example 2:

Input: nums = [7,7], k = 1

Output: [7]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //mp[element] -> element frequency.
        for (int x:nums){
            mp[x]++;
        }
        vector<vector<int>> bucket (nums.size()+1); //bucket[freq] = {elems with that freq}; 
        //Max frequency of any element will be the size of the nums array, so to get to that index,
        //we need to initialise bucket with size + 1 to since its 0 based indexing, 
        for (auto x:mp ){
            bucket[x.second].push_back(x.first); //since we are accessing an index of bucket, we need to initialize it as well. 
        }
        //return last k elements. 
        vector<int> ans; 
        for (int i = bucket.size()-1 ; i>=0 ; i--){
             for(int num : bucket[i]) {
                ans.push_back(num);
                if(ans.size() == k)
                return ans; 
            }
        }
        return ans; 

    }
};
//TC=SC=O(n) where n is the size of the input array.