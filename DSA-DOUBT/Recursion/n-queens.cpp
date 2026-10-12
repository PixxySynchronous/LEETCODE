class Solution {
public:
    bool isSafe (int col, int row, vector<vector<int>>& board, int n){
        // since we are filling from col 0 - n, we only need to see all the conditoins
        // to our left of the board as the right side of the board is still empty as it is unfilled. 
        //row check:
        int x = row; 
        int y = col; 
        while (y>=0){
            if (board[x][y] == 1)
                return false; 
            y--; 
        }
        //we need 2 diagnol checks, one which checks the above diagnols, where both x and y get -- by one. 
        x = row;
        y= col; 
        while (x>=0 && y>=0){
            if (board[x][y]==1)
                return false; 
            x--;
            y--; 
        }
        // to chekc the bottom going diagnol the col gets -- but rows increase
        x = row; 
        y = col ; 
        while (x<n && y>=0){
            if (board[x][y] == 1)
                return false; 
            x++;
            y--; 
        }
        //all checks done. 
        return true; 
    }
    void addAns (vector<vector<int>>& board,vector<vector<string>>&ans, int n){
        
        vector<string> temp2; 
        //we will traverse the board. Wherever queen is placed we put Q, else we put .
        for (int i = 0; i<n ; i++){
            string temp; 
            for (int j = 0; j<n; j++){
                if (board[i][j]==1)
                    temp.push_back('Q');
                else
                    temp.push_back('.');
            }
            temp2.push_back(temp); 
        }
        ans.push_back(temp2); 
        return; 
    }
    void solve (int col,vector<vector<int>>& board,vector<vector<string>>&ans,int n){
        if (col == n){
            // we have reached an answer. 
            addAns (board, ans, n); 
            return; 
        }
        // we will traverse every row of the current column. 
        for (int row = 0 ; row < n ; row ++){
            if (isSafe(col,row,board,n)){
                board[row][col] = 1; 
                //now that we have put a queen in this col we check all eprmutations of other cols
                solve (col+1, board, ans, n);
                //once we are back we need to try a different row position for the current queen so we need to remove her from curr row position and place her in the next one, which happens in the next iteration of the loop 
                board[row][col] = 0; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if (n==1)
            return {{"Q"}}; 
        vector<vector<string>> ans; 
        vector<vector<int>> board (n, vector<int> (n,0)); 
        solve (0,board,ans,n);
        return ans; 
    }
};

//TC: o(n^n) because for each column, we have n choices for the row, and we have n columns, so the total number of possible arrangements is n^n. 
// The space complexity is due to the board and the recursion stack.
//TC: o(n^n) because for each column, we have n choices for the row, and we have n columns,  and SC: o(n^2) for board and o(n) for recursion stack.
// is safe function can be optimised to o(1) by using 3 extra arrays to keep track of the rows and diagonals.