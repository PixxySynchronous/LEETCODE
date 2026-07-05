// class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans (nums.size());
        int n = nums.size(); 
        ans[0] = 1;
        int suffix = 1; 
        for (int i = 1; i<nums.size(); i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        for (int i = n-1; i>=0 ; i--){
            ans[i] = ans[i]*suffix; 
            suffix *= nums[i];
        }  
        //Logic here is the following: For ans array's ith element i need prefix[i] (nums[0]*nums[1]*..nums[i-1]) and suffix[i]. SO what I did is stored the prefixes in the answer array and then, from left to right, I started to multiply the suffix with each element. Suffix for last element will be one. Suffixfor the second last element would be suffix of last element * second last element (nums[i], i starting from n-1)
      
        return ans; 
    }
};