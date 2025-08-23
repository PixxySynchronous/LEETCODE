//Leetcode-442 Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 
//WHhile doing this question would be easier with 2 for loops nested, we have to do it in O(n) time and constant space. So we can use the fact that the numbers are in the range of 1 to n and use the array itself to mark the numbers that we have seen. However i came up with a different solution. 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        int j=0;
             vector<int> output;
        int mask[100001] = {0}; 
        for (int i=0;i<size;i++){
            if(mask[nums[i]]==1){
             output.push_back(nums[i]);
                j++;
                continue;
            }
            mask[nums[i]]=1;
        }
        return output;
    }
};

//This solution works in O(n) time and uses O(n) space. I am aware that this is not the most optimal solution, but it is a valid one. The optimal solution would be to use the array itself to mark the numbers that we have seen, but I wanted to try a different approach.I couldnt figure out how to use the array itself to mark the numbers that we have seen without using extra space.But this idea was mine and gpt helped me only with the vector syntax as it is not yet covered in my course.