//  You are given a 2D binary matrix mat[ ][ ], where each cell 
//  contains either 0 or 1. Your task is to find the maximum area of a rectangle that
//  can be formed using only 1's within the matrix.

// Input: mat[][] = [[0, 1, 1, 0],
//                 [1, 1, 1, 1],
//                 [1, 1, 1, 1],
//                 [1, 1, 0, 0]]
// Output: 8
// Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
// [1, 1, 1, 1]
// [1, 1, 1, 1]
// and area is 4 * 2 = 8.

class Solution {
  public:
  // this part is same as largest area in histogram problem.
  //thinking approach is how to minimize this 2d problem in terms of 1d problem.
  // we do this by cinsidering height of row as a histogram bar height.
    vector <int> nextSmallestElement (vector <int> &heights){
        stack<int> stack; 
        stack.push(-1); 
        vector <int> ans; 
        for (int i = heights.size() - 1 ; i >= 0 ; i --){
            while (stack.top()!= -1 && heights [stack.top()] >= heights[i]){
                stack.pop(); 
            }
            ans.push_back (stack.top()); 
            stack.push(i); 
        }
        reverse (ans.begin(), ans.end()); 
        return ans; 
    } 
    vector <int> prevSmallestElement (vector <int> &heights){
        stack<int> stack; 
        stack.push(-1); 
        vector <int> ans; 
        for (int i = 0 ; i < heights.size() ; i ++){
            while (stack.top()!= -1 && heights [stack.top()] >= heights[i]){
                stack.pop(); 
            }
            ans.push_back (stack.top()); 
            stack.push(i); 
        }
        return ans; 
    }
    int largestRectangleArea (vector <int> &heights){
        vector <int> next; 
        vector <int> prev; 
        int area = 0; 
        int maxArea = 0;
        next = nextSmallestElement (heights); 
        prev = prevSmallestElement (heights); 
        for (int i = 0; i < heights.size(); i++){
            int p = next [i]; 
            if (p == -1) p = heights.size(); 
            int q = prev [i]; 
            int width = p-q-1; 
            area = heights[i]*width; 
            maxArea = max (area, maxArea);
        }
        return maxArea; 
    }

    //the logic to solve this problem is to treat each row as the base of a histogram
    // and calculate the max area for each row using the heights calculated from previous rows.
    // we maintain a heights array which is updated for each row.
    // if mat[i][j] == 1 then heights[j]++ else heights[j] = 0
    // then we calculate the largest rectangle area for the updated heights array.
    // we keep track of the maximum area found so far and return it at the end.
    int maxArea(vector<vector<int>> &mat) {
        vector <int> heights (mat[0].size(), 0 ) ;
        int area = 0 ; 
        int maxArea = 0 ; 
        if (mat.size() == 0 ) return -1; 
        if (mat[0].size() ==0 ) return -1; 
        for (int i =0 ; i< mat.size() ; i++){
            for (int j = 0 ; j < mat[0].size() ; j++){
                if (mat[i][j] == 1){
                    heights[j]++; 
                }
                else 
                heights[j] = 0; 
            }
            area = largestRectangleArea (heights); 
            maxArea = max (area , maxArea); 
        }
        return maxArea; 
        
    }
};

