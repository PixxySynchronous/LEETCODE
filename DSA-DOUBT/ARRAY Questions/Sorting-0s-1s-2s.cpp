// 75. Sort Colors
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //For this question, i will use 3 pointers.
        //Pointer i will be at 0 and will keep track of the index where the next '0' is supposed to be. 
        //Pointer k will be at the last index and will keep track of the index where the next '2' will come. 
        //Pointer j will traverse the array.
        int i = 0; 
        int k = nums.size() -1 ;
        int j = 0 ; 
        while (j<=k){
        //We use a while loop because, if we use a for loop and traverse the entire array,
        //eventaully after the array is sorted, pointer j will start to encounter all of sorted 2s and then swap them with previous elements as k keeps on decreaseing. 
            if (nums[j] == 0){
                swap(nums[i], nums[j]);
                i++; 
                j++;
            }
            else if (nums[j] == 2){
                swap (nums[k], nums[j]);
                k--; 
                //We dont increment j here as it is possible we have swapped a 0 with a 2.
                //If it is a 0, we will catch it in the next iteration. 
            }
            else 
                j++;
        }
    }
};