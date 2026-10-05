// Balanced Splits of a Binary String
// Solved
// Difficulty: EasyAccuracy: 50.02%Submissions: 32K+Points: 2
// Given binary string s . find the maximum number of substrings it can be splitted into such that all substrings have equal number of 0s and 1s. If it is not possible to split s satisfying the conditions then return -1.

// Examples:

// Input: s = "0100110101"
// Output: 4
// Explanation: 
// The required substrings are 01, 0011, 01 and 01.
// Input: s = "0111100010"
// Output: 3
// Input: s = "0010"
// Output: -1
// Constraints:

// 1 ≤ s.size() ≤ 105

class Solution {
  public:
    int maxSubStr(string &s) {
        // Good question and it tells me about a new pattern.
        // Whenever you want an equal amount of smth, we can use a simple counter
        // which increments on 1 and decrements on other type 
        // Wheneven the counter equals 0, we have found a match 
        int counter = 0; 
        int ans = 0; 
        for (char c: s){
            if (c=='0')
                counter++;
            else
                counter --; 
            if (counter == 0)
                ans++; 
        }
        if (counter != 0) //unequal 0s and 1s, entrie string is not splittable. 
            return -1; 
        return ans; 
        
    }
};
