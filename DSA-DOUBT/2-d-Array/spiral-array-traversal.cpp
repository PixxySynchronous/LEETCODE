//Leetcode 54 
// Given an m x n matrix, return all elements of the matrix in spiral order.

 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { //testcase: : matrix = [[1,2,3],[4,5,6],[7,8,9]]
        int row = matrix.size(); //total number of rows
        int col = matrix [0].size() ;  //total columns 
        int lastrow = matrix.size() - 1; //index of lastrow
        int lastcol = matrix [0].size() - 1 ; //index of lastcol 
        int firstrow = 0 ; 
        int firstcol = 0 ; 
        int i = 0 ; //traversing rows
        int j = 0 ; //traversing cols
        int count = 0 ; //elements in output vector should = total number of elements. 
        vector <int> output; 
        int total = row*col ; 
        while (count < total){
            for (j = firstcol; j<=lastcol && count < total ; j++){  //j = firstcol as if we kept normal indexing then corner elements would be repeated
                output.push_back(matrix[firstrow][j]); // 1,2,3 pushed 
                count ++ ; 
            }
            firstrow++; //firstrow has been covered so we discard it and get a new first row. That s what i is initialized to. 
            for (i=firstrow; i<=lastrow && count < total ; i++){
                output.push_back(matrix[i][lastcol]); //6,9 pushed and last col covered so we subtract it after loop 
                count ++ ; 
            }
            lastcol--; 
            for (j=lastcol; j>=firstcol && count < total ; j--){ //j =lastcol which was subtracted before to ensure 9 is not printed twice 
                output.push_back(matrix[lastrow][j]); 
                count ++ ; 
            } 
            lastrow --; 
            for (i = lastrow; i>=firstrow && count < total ; i--){
                output.push_back(matrix[i][firstcol]); 
                count ++ ; 
            }
            firstcol++; 

        }
        return output; 
    }
};


//I could make up the logic of reducing the array to the non traversed part by indexing lastcils and rows and then subtracting them ... similarly indexing firstcols and rows and incrementing them.
//I couldn't figure out how to correctly code that logic as using while loop first i had to adjust i and j several types and with for loop we needed to initialize i and j not with 0 or their current value but 
//with the columsn or rows they would be starting in. That was figured via ai. 