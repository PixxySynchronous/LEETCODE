//Leetcode 189 
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
 



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    //While my initial line of thought was to brute force the question,whose code is written below, upon being give a hint about reversing th array, I did recognize that the array splits into 2 distinct parts. If we consider each part as a single element, all we have to do is reverse those 2 elements. I did not code that logic however as i did not know how to group several elements and treat them as one and therefore seeked help of AI which gave me a simple and effective ans:
    int size = nums.size();
    k=k%size; //Rotating an array of elements n 2n times just means rotating the array 0 times as k%n=0
    reverse (nums.begin(),nums.end());//reverse the whole array 
    reverse (nums.begin(),nums.begin()+k); //Unreverse the first distinct element (combination of elements)
    reverse (nums.begin()+k,nums.end());//Unreverse the second distinct element 
        

    }
};
    //First thought of solution:
        // int size= nums.size();
        // while(k>0){
        // int temp = nums[size-1];
        // //Shift all elements to the right, starting from the end, to not have an extra temp variable.
        // for (int i=size-2;i>=0;i--){
        //     nums[i+1]=nums[i];
        // }
        // nums[0]=temp;
        // k--;
        // }
//This works but is not optimised as time complexity is o(k*n) and hence the last test case scenario failed. 


