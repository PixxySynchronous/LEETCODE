// 3Sum
// Medium
// Topics
// Company Tags
// Hints
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

// The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]

// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //3 sum is just 2 sum with one variable fixed. 
        //so instead of target being target, target becomes target - fixed number
        //we sort the array in nlogn. No issue as we need to return the number, not the indices. 
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans; 
        for (int i = 0 ; i<nums.size(); i++){
            int target = 0 - nums[i]; 
            int left = i+1; //we search only to the right of i as we dont have to reconsider the same triplets. Elements to the left of i have already been processed and their triplets have already been saved.
            if (i>0 && nums[i] == nums[i-1]) continue; //Since the elements to the left of i is already considered to be processed, if the current element is the same as the previous one, we will just get the same triplet, so we skip that.           
            int right = nums.size()-1; 
            while (left<right){
                vector<int> set;  //declared in loop so that for each loop it gets cleared. 
                //No need to do the below checks since we are starting from the right of i. 
                // if (right == i){ 
                //     right++; 
                //     continue; 
                // } 
                // if (left == i){
                //     left -- ;
                //     continue; 

                if (nums[right] + nums[left] > target){
                    right --;
                }
                else if (nums[right] + nums[left] < target){
                    left ++;
                }
                else{
                    set.push_back(nums[i]);
                    set.push_back(nums[right]);
                    set.push_back(nums[left]);
                    ans.push_back(set); 
                    //ans.push_back({nums[i], nums[left], nums[right]}); is the same thing. 
                    right --; 
                    left ++; //once we have moved the pointers of left and right, we need to make sure that the next elements they will be pointing to (elements they point to after getting incremented right now)
                    // are not the same elements they were pointing to before, because if that happens, in effect, we have not moved the pointers at all, because theyd be still pointing to the same value, so we will
                    // keep incrementing or decrementing till the element found is different. 
                    while (left<right && nums[left] == nums [left-1])
                        left++; 
                    while (left<right && nums[right]==nums[right+1])
                        right--; 
                }
            }
        }
        return ans; 
    }
};
