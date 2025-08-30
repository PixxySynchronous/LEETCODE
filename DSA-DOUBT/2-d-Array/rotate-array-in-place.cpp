// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size()==1)
        end; 
        //Approach is to take the ith row and put it in the j-i column
        //Will need to store all the rows first but then it wont be in-place. 
        //took a hint from discusion and gpt about the logic only and got the idea of swapping arr[i][j] with arr [j][i] and then reversing 
        int i = 0; 
        int j = 0; 
        for (i=0;i<matrix.size();i++){
            for (j=i+1;j<matrix[0].size();j++){ 
                //if we write j=0 we will just reswap all the elements again. Since swapped elements go to the
                //ith column (menaing if row 0 swapped, elements go to the column 0, we initialize from j=i+1 so we dont revisit that column.)
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        i=0; 
        for (i=0;i<matrix.size();i++){
            for (j=0;j<matrix[0].size()-2;j++){
                swap(matrix[i][j],matrix[i][matrix[0].size()-1-j]);
            }
        }
        

    }
};