// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[1, 1, 0],
//                 [0, 1, 0],
//                 [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1st person and 1st person does
// not know anyone. Therefore, 1 is the celebrity person.


class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        stack <int> stack; 
        int n = mat.size();

        for (int i = 0 ; i < n ; i++){
            stack.push(i); 
        }
        //put all memebers in the stack, take 2 out
        // if a knows b then a cant be celebrity
        //if a doesnt know b then b cnat be celebrity 
        //through thids we eleminate one and then redo process. 
        //can be done via stack or 2 pointer via i++ j-- ;
        while (stack.size()!=1){
            int a = stack.top(); 
            stack.pop(); 
            int b = stack.top(); 
            stack.pop(); 
            if (mat[a][b] == 1){
                stack.push(b); 
            }
            else 
                stack.push(a);
            
        }
        int candidate = stack.top(); 
        for (int i = 0 ; i < n ; i ++){
            if (i == candidate) continue; 
            if (mat [candidate][i] == 1) return -1; 
            if (mat [i][candidate] != 1) return -1; 
        }
        return candidate; 
        
    }
};

// class Solution {
// public:
//     int celebrity(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int i = 0, j = n - 1;

//         // Elimination phase
//         while (i < j) {
//             if (mat[i][j] == 1)
//                 i++;      // i knows j → i eliminated
//             else
//                 j--;      // i doesn't know j → j eliminated
//         }

//         int candidate = i;

//         // Verification phase
//         for (int k = 0; k < n; k++) {
//             if (k == candidate) continue;

//             // Candidate should know nobody
//             if (mat[candidate][k] == 1) return -1;

//             // Everybody should know candidate
//             if (mat[k][candidate] == 0) return -1;
//         }

//         return candidate;
//     }
// };
