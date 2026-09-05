// 73. Set Matrix Zeroes
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Since we need to do this in place, we need to store the information of 
        //which row and which column needs to be turned to 0 entirely in the matrix 
        //itself. This can be done by making the first element of the row which needs to
        //be turned to 0 as 0 and the first element of the column which needs to be 0 to 0. However We run into 3 problems because of this.
        //What if the first element of that row or column is already 0? and also the 0,0 element contains information for the row or the column to be tunred to 0?
        // To fix this we require a boolean variable. 
        bool firstrow = false; 
        bool firstcol = false; 
            //STORE if first row has a 0.
            for (int j =0 ; j<matrix[0].size(); j++){
                if ( matrix[0][j] == 0){
                    firstrow = true; }
            }
            //STORE if first column has a 0. 
            for (int i =0 ; i<matrix.size(); i++){
                if ( matrix[i][0] == 0){
                    firstcol = true; }
            }
        //Scan the rest of the matrix and then do the markings. Now information wont be lost as its already in bool var. 
        for (int i =1 ; i<matrix.size(); i++){
            for (int j =1 ; j<matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0; 
                    matrix[0][j] = 0;
                }
            }
        }
        //Check the row markers and make the respective rows 0. We dont check row 0,becasue if thats 0, the entire 0th row will become 0, modifying the markers.We check the 0th row in the end.
        for (int i = 1 ; i<matrix.size(); i++){
            if (matrix[i][0] == 0){
                for (int j = 0 ; j<matrix[0].size(); j++){
                    matrix[i][j] = 0; 
                }
            }
        }
        //Check the column markers and make the respective rows 0. We dont check column 0,0 becasue if thats 0, the entire 0th row will become 0, modifying the markers.We check the 0th column in the end.
        for (int j = 1 ; j<matrix[0].size(); j++){
            if (matrix[0][j] == 0){
                for (int i =0 ; i<matrix.size(); i++){
                    matrix[i][j] = 0; 
                }
            }
        }
        if (firstrow==true){
            for (int j= 0; j<matrix[0].size(); j++){
                matrix[0][j] = 0; 
            }
        }
        if (firstcol==true){
            for (int i= 0; i<matrix.size(); i++){
                matrix[i][0] = 0; 
            }
        }

    }
};