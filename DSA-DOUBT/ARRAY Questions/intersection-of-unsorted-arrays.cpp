// 349. Intersection of Two Arrays
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; 
        unordered_set<int> st; 
        unordered_set<int> added; //we dont have to add an element twice in the ans array,so we keep track of added elements through this set. 
        for (auto i: nums1)
            st.insert(i); 
        for (auto i:nums2){
            if (st.count(i) && !added.count(i)){
                added.insert(i);
                ans.push_back(i);
            } 

        }
        return ans; 
    }
};