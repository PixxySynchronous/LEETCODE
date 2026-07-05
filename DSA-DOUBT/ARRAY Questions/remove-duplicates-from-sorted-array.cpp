// 26. Remove Duplicates from Sorted Array
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        //k is number of unique elements, starting from 1 cuz atleast one element
        //will always be unique. It also serves as a boundary. All elements behind k are unique. Whenever a new element is found, its swapped with nums[k] and then k++. 
        for (int i = 1; i<nums.size(); i++){
            if (nums[i] == nums[k-1]){
                continue;
            }
            else{
                swap (nums[i], nums[k]);
                k++;
            }
        }
        return k; 
    }
};