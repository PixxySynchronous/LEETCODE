// Valid Sudoku
// Medium
// Topics
// Company Tags
// Hints
// You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

// Each row must contain the digits 1-9 without duplicates.
// Each column must contain the digits 1-9 without duplicates.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
// Return true if the Sudoku board is valid, otherwise return false

// Note: A board does not need to be full or be solvable to be valid.

// Example 1:



// Input: board =
// [["1","2",".",".","3",".",".",".","."],
//  ["4",".",".","5",".",".",".",".","."],
//  [".","9","8",".",".",".",".",".","3"],
//  ["5",".",".",".","6",".",".",".","4"],
//  [".",".",".","8",".","3",".",".","5"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".",".",".",".",".",".","2",".","."],
//  [".",".",".","4","1","9",".",".","8"],
//  [".",".",".",".","8",".",".","7","9"]]

// Output: true

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Ok so approach is to store all the values in rows in 9 separate sets, 
        //then stroe all the elements in the cols in 9 separate sets
        // then store all the elements in each box in 9 different sets. 
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        for (int i=0 ; i<9 ; i++){
            for (int j = 0; j<9 ; j++){
                if (board[i][j] == '.')
                    continue; 
                char num = board[i][j]; 
                int box = (i/3)*3 + (j/3);
                //considering we label all the boxes from 0 to 8, 
                //this formula tells us the exact box number for each coordinate. 
                if (rows[i].count(num)||cols[j].count(num)||boxes[box].count(num))
                    return false; 
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }
        return true; 

    }
};
