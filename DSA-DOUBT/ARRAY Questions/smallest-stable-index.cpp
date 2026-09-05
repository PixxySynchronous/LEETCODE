
// Testcase
// Code
// Test Result
// 3903. Smallest Stable Index I
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums of length n and an integer k.

// For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

// In other words:

// max(nums[0..i]) is the largest value among the elements from index 0 to index i.
// min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
// An index i is called stable if its instability score is less than or equal to k.

// Return the smallest stable index. If no such index exists, return -1.

 

// Example 1:

// Input: nums = [5,0,1,4], k = 3

// Output: 3

// Explanation:

// At index 0: The maximum in [5] is 5, and the minimum in [5, 0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
// At index 1: The maximum in [5, 0] is 5, and the minimum in [0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
// At index 2: The maximum in [5, 0, 1] is 5, and the minimum in [1, 4] is 1, so the instability score is 5 - 1 = 4.
// At index 3: The maximum in [5, 0, 1, 4] is 5, and the minimum in [4] is 4, so the instability score is 5 - 4 = 1.
// This is the first index with an instability score less than or equal to k = 3. Thus, the answer is 3.
// Example 2:

// Input: nums = [3,2,1], k = 1

// Output: -1

// Explanation:

// At index 0, the instability score is 3 - 1 = 2.
// At index 1, the instability score is 3 - 1 = 2.
// At index 2, the instability score is 3 - 1 = 2.
// None of these values is less than or equal to k = 1, so the answer is -1.
// Example 3:

// Input: nums = [0], k = 0

// Output: 0

// Explanation:

// At index 0, the instability score is 0 - 0 = 0, which is less than or equal to k = 0. Therefore, the answer is 0.

 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109
// 0 <= k <= 109

class Solution {
public:
    // int maxElem (vector<int>& nums, int endIndex){
    //     int maxElem = -1; 
    //     for (int i = 0; i<= endIndex; i++){
    //         if ( nums[i]> maxElem)
    //             maxElem=nums[i];
    //     }
    //     return maxElem; 
    // }
    // int minElem (vector<int>& nums, int startIndex){
    //     int minElem = INT_MAX; 
    //     for (int i = startIndex ; i< nums.size(); i++){
    //         if ( nums[i]< minElem)
    //             minElem=nums[i];
    //     }
    //     return minElem; 
    // }
    int firstStableIndex(vector<int>& nums, int k) {
      
    //     for (int i = 0 ; i<nums.size();i++){
    //         int small = minElem (nums,i); 
    //         int big = maxElem (nums,i); 
    //         if (big-small<=k)
    //            return i;  
    //     }
    //     return -1; 

    // }
    //Recognize: you want max on left and min on right. This wanting of info from left and the right indicates prefix and suffix!!
    int n = nums.size(); 
    vector<int> maxPrefix(n);
    maxPrefix[0]=nums[0]; 
    for (int i = 1; i<nums.size();i++){
        int maxPref = max(maxPrefix[i-1], nums[i]);
        maxPrefix[i]=maxPref;
    }
    vector<int>minSuffix(n); 
    minSuffix[n-1] = nums[n-1]; 

    for (int i = n-2; i>=0 ;i--){
        int minSuff = min(minSuffix[i+1], nums[i]);
        minSuffix[i]=minSuff;
    }

    for (int i = 0 ; i<nums.size() ; i++){
        if (maxPrefix[i] - minSuffix[i] <=k)
            return i; 
    }
    return -1;
    }

};class Solution {
public:
    // int maxElem (vector<int>& nums, int endIndex){
    //     int maxElem = -1; 
    //     for (int i = 0; i<= endIndex; i++){
    //         if ( nums[i]> maxElem)
    //             maxElem=nums[i];
    //     }
    //     return maxElem; 
    // }
    // int minElem (vector<int>& nums, int startIndex){
    //     int minElem = INT_MAX; 
    //     for (int i = startIndex ; i< nums.size(); i++){
    //         if ( nums[i]< minElem)
    //             minElem=nums[i];
    //     }
    //     return minElem; 
    // }
    int firstStableIndex(vector<int>& nums, int k) {
      
    //     for (int i = 0 ; i<nums.size();i++){
    //         int small = minElem (nums,i); 
    //         int big = maxElem (nums,i); 
    //         if (big-small<=k)
    //            return i;  
    //     }
    //     return -1; 

    // }
    //Recognize: you want max on left and min on right. This wanting of info from left and the right indicates prefix and suffix!!
    int n = nums.size(); 
    vector<int> maxPrefix(n);
    maxPrefix[0]=nums[0]; 
    for (int i = 1; i<nums.size();i++){
        int maxPref = max(maxPrefix[i-1], nums[i]);
        maxPrefix[i]=maxPref;
    }
    vector<int>minSuffix(n); 
    minSuffix[n-1] = nums[n-1]; 

    for (int i = n-2; i>=0 ;i--){
        int minSuff = min(minSuffix[i+1], nums[i]);
        minSuffix[i]=minSuff;
    }

    for (int i = 0 ; i<nums.size() ; i++){
        if (maxPrefix[i] - minSuffix[i] <=k)
            return i; 
    }
    return -1;
    }

}; //this is tc o(n) and sc is o(n) for the prefix and suffix arrays.
//can also be done with only 1 prefix array and a variable to store the min suffix value.