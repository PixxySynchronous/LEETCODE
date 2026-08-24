// roblem statement
// You are given an array 'ARR' consisting of 'N' integers. You need to rearrange the array elements such that all negative numbers appear before all positive numbers.

// Note:
// The order of elements in the resulting array is not important.
// Example:
// Let the array be [1, 2, -3, 4, -4, -5]. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-3, -5, -4, 2, 4, 1].
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 5 * 10^4
// -10^5 <= ARR[i] <= 10^5

// Where  ‘T’ represents the number of test cases and ‘N’ represents the number of elements present in the array.
#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // Since in this question the order of elements is not relevant, this can be done through
    //a simple 2 pointer approach. 
    int i = 0 ; //Keeps track of where the next negative number should go
    for (int j = 0 ; j<nums.size() ; j++){
        if (nums[j]<0){
            swap(nums[i], nums[j]);
            i++;
        }
    }
    return nums; 
}
// NOTE: If relevant order was to be preserved, instead
// of swapping the elements, we will have shift all the 
// elements between i and j to the right. This, at its worst case would be o(n2)
// If using extra space is allowed, then this can be done in o(n)