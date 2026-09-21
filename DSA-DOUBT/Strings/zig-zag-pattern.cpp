// 6. Zigzag Conversion
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"

class Solution {
public:
    string convert(string s, int numRows) {
       vector<string> rows (numRows); //each element holds a string. 
       // rows[0] is an element which stores all the elements which should appear in the row 0 
       // rows[i] is an element which stores all the characters which appear in row i. 
       int x = 0; //traverses the string. 
       int i = 0; // this traverses the rows. We go from 0 -> number of rows - 1 first. Then we go from. number of rows - 1 --> 0 and repeat till we traverse the entire string. 
       bool goingUp = false; 
       bool goingDown = true; 
       if (numRows == 1) //baseCase. If rows == 1 we cant do i-- below as then 0 -> -1 causing an error. 
            return s; 
       while (x<s.size()){
            //rows[i].append(s[x]); //.append expects a string not a char!
            rows[i]+=s[x]; //add current element to the current row string.
            x++; 
            if (goingDown){
                if (i != numRows - 1){
                    i++; //if going down increase the row. 
                    continue; 
                }
                else{
                    goingDown = false;
                    goingUp = true; 
                    i--; //else go up. 
                    continue; 
                } 
            }
            if (goingUp){
                if (i!=0){
                    i--; //if going up decrease the row. 
                    continue;  
                }
                else{
                    i++; 
                    goingDown = true; 
                    goingUp = false; 
                    continue;
                }
            }
        }
        string ans = ""; 
        for (int i = 0 ; i<numRows ; i++)
            ans.append(rows[i]); //append all rows like rows{0} + rows{1} etc to form the final string. 
        return ans; 
    }
};