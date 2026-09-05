// 3876. Construct Uniform Parity Array II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array nums1 of n distinct integers.

// You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

// For each index i, you must choose exactly one of the following (in any order):

// nums2[i] = nums1[i]​​​​​​​
// nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
// Return true if it is possible to construct such an array, otherwise return false.

 

// Example 1:

// Input: nums1 = [1,4,7]

// Output: true

// Explanation:​​​​​​​​​​​​​​

// Set nums2[0] = nums1[0] = 1.
// Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3.
// Set nums2[2] = nums1[2] = 7.
// nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.
// Example 2:

// Input: nums1 = [2,3]

// Output: false

// Explanation:

// It is not possible to construct nums2 such that all elements have the same parity. Thus, the answer is false.

// Example 3:

// Input: nums1 = [4,6]

// Output: true

// Explanation:

// Set nums2[0] = nums1[0] = 4.
// Set nums2[1] = nums1[1] = 6.
// nums2 = [4, 6], and all elements are even. Thus, the answer is true.
 

// Constraints:

// 1 <= n == nums1.length <= 105
// 1 <= nums1[i] <= 109
// nums1 consists of distinct integers.
 
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEven = INT_MAX; 
        int minOdd = INT_MAX; 
        for (int i: nums1){
            if ( i%2 == 0){
                minEven = min(minEven,i); 
            }
            else{
                minOdd = min(minOdd,i); 
            }
                
        }
        if (minOdd < minEven){ 
            //smallest element is odd so we try to make entire array odd.
            // for (int i = 0 ; i<nums1.size() ; i++){
            //     if(nums1[i] % 2 != 0) //already odd. 
            //         continue; 
            //     else {
            //         int x = nums1[i] - minOdd; //even - odd = odd. 
            //         if (x<=0) //cant be converted to odd. 
            //                 return false; 
            //     }
            // }
            // return true; 
            //***************** above loop is redundant
            //if smallest element is odd, all elements can be made odd as odd elements remain odd and
            // even elements become even - minOdd which is gauranteed to be >1 as minOdd is the smallest element in the array. 
            return true; 
        }
        else { 
            //convert all elements to even 
            // for (int i = 0 ; i<nums1.size() ; i++){
            //     if(nums1[i] % 2 == 0)
            //         continue; 
            //     else {
            //         int x = nums1[i] - minOdd; //odd - odd = even. 
            //         if (x<=0) //cant convert to even. 
            //                 return false; 
            //     }
            // }
            // return true; 
            //************************** above loop is redundant. 
            //if the smallest element is even, we need to make everything even.
            // even numbers stay even and odd numbers: odd- odd = even. 
            //BUT there will be a case where we encounter minOdd - minOdd which is = 0 
            //This means that whenever there is an odd element in the array and the smallest element is even,
            //conversion is not possible. 
                if (minOdd == INT_MAX) //no odd elements. 
                    return true; 
                else 
                    return false; 

        }
  
       
           
    }
};