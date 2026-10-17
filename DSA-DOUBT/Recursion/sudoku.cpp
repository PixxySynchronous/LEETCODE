class Solution {
public:
    bool isSafe (int row, int col, int value ,vector<vector<char>>& board){
        for (int i = 0 ; i<9; i++){
            if (board[row][i] == value +'0')
                return false; 
            if (board [i][col] == value + '0')
                return false; 
            //integer division finds the box's starting position; i / 3 and i % 3 traverse the nine cells inside it.
            if (board [3*(row/3) + i%3][3*(col/3) + i/3] == value + '0')
                return false; 
        }
        return true; 
    }
    bool solve (vector<vector<char>>& board){
        for (int i = 0 ; i<9 ; i++){
            for (int j = 0; j<9 ; j++){
                if (board[i][j]== '.'){
                    for (int value = 1; value <=9 ; value ++){
                        if (isSafe (i,j,value,board)){
                            board[i][j] = value + '0'; 
                            bool ans = solve(board); 
                            if (ans == true) //means this number can fit in the box 
                                return true; 
                            else{
                                board[i][j] = '.'; //number cant fit we backtrack. 
                            }
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve (board);

    }
};