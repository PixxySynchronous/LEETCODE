//Leetcode 1752
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].




class Solution {
public:
    bool check(vector<int>& arr) {
        //the condition of arr[i-1]>arr[i] should only break once or none times in these tyoes of arrays 
        //eg) [3,4,5,1,2] 3<4<5>1>2 and 2<3 so broken once 
        // eg)[2,1,3,4] 2>1<3<4 4>2 so broken twice 
        int counter=0;
        for (int i=1;i<arr.size();i++){
            if (i==arr.size()-1){
                if (arr[i]>arr[0]){
                counter++;
                
            }}
            if(arr[i-1]>arr[i])
            counter++;
        }
        if(counter>1)
        return false;
        return true;
    }
        
    
};

//My initial logic was to unrotate the array at every index and check that array if it sorted or not. I tried to code that but got the order of unrotation off, since i knew how to rotate right, here i had to rotate left....also the time complexity of that solution wouldve been high, even though no constraints were given in the question. This current logic is given by the youtube video because i could not think of it. i was able to code it once i got the logic. Lesson leaarnt is to check the Cases where in output is true and try to find patterns there. 