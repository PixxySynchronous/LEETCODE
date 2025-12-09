//You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 
 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Approach is to treat the 2d array as a linear array written in ascending order. meaning start =0 and index of last element will be
        //totol elements - 1. Then take out the index of mid. Now to gain access of the value of the element in mid we use mid/col size and 
        //mid%col size
        //This works because lets say we have a 3x3 matrix so the elements 0 1 2 will be in row 0 so /colsize gives 0 and %colsize gives the col number 
        int start = 0 ; 
        int total = matrix.size()*matrix[0].size(); 
        int end = total -1 ;
        int cols = matrix[0].size(); 
        int mid = start + (end - start)/2;
        while (start <= end){
            int element = matrix [mid /cols][mid%cols];
            if (element == target){
                return 1 ;
            }
            else if (element < target)
            start = mid +1; 
            else
            end = mid -1; 
            mid = start + (end - start)/2;
        }
        return 0 ; 
        
    }
};