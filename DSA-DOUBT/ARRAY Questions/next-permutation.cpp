// 31. Next Permutation
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // given a number like 127431 
        // we first need to find the postion where the actual swtich of digits is supposed
        // to take place. Like here we notice that 7431 is already the biggest number it can be, but 27431 is not. So we can form a bigger number by switching 2. 
        // We switch 2 with the smallest ppssible number to its right but it should be bigger than 2. so 3 in this case. we get 137421 Now to make this number even smaller we just need to reverse the ascending part to descending which gives ans 131247
        int i = nums.size()-1; //start searching from the right
        while (i >= 1 && nums[i-1] >= nums[i]){ //the order is ascending if the element before the curr element is bigger or equal. 
            i--; 
        }
         if (i==0){
            // The entire digit is the biggest it can be eg 321 so in this case as the qsn specifies we need to return the smalles possible permutation which would be the reverse of the digit i.e 123
            reverse (nums.begin(), nums.end()); 
            return; 

        } 
        // Now we need to swap position i-1. With the smallest possible number to its right. 
        i--;
        int j = nums.size()-1; //smallest possible numbers will be at the end as the end is in an ascending order. 
        while (nums[j] <= nums[i]) //cant swap with an equal or else the permutation doesnt decrease. 
            j--; 
        swap (nums[i], nums[j]); 
        reverse (nums.begin() + i + 1 , nums.end());
        return; 
    }
};