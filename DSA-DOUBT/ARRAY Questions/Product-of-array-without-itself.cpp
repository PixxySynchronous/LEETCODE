// class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans (nums.size());
        int n = nums.size(); 
        ans[0] = 1; //prefix of first element is 1, as there are no elements before it.
        int suffix = 1; 
        for (int i = 1; i<nums.size(); i++){
            ans[i]=ans[i-1]*nums[i-1]; //prefix of the current element is prefix of previous element * previous element.
        }
        for (int i = n-1; i>=0 ; i--){
            ans[i] = ans[i]*suffix; // ans[i] already has the prefix of the current element, we multiply it with the suffix to get the final answer.
            suffix *= nums[i]; // suffix of the next element is suffix of the current element * current element.
        }  
        //Logic here is the following: 
        //For ans array's ith element i need prefix[i] (nums[0]*nums[1]*..nums[i-1]) and suffix[i]. 
        //SO what I did is stored the prefixes in the answer array and then, from left to right,
        // I started to multiply the suffix with each element. 
        //Suffix for last element will be one. Suffixfor the second last element would be suffix 
        //of last element * second last element (nums[i], i starting from n-1)
      
        return ans; 
    }
};