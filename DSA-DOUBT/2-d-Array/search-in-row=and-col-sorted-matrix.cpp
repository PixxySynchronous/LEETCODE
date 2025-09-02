// LEETCODE 240  Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       //Approach is to start at first row last col. if target is bigger than that then we can do row++ as target wont be in that row and if target is
       //lesser than that we can do col -- . 
       int row = 0 ;
       int col = matrix[0].size() - 1;
       while (row < matrix.size() && col >= 0 ){
            int mid = matrix [row][col]; 
            if (target == mid )
            return 1; 
            else if (target > mid)
            row ++;
            else
            col --; 
       }
       return 0; 

    }
};

//Needed help with the approach. 