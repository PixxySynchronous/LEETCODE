// 14. Longest Common Prefix
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

class Solution {

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
            return ""; 
        //We need to compare characters of the first string to the characters of the other string. 
        //Like first we compare the first character of string 0 with firrst character of all the 
        //other strings. Then we compare the second character of string 0 with the second character of all the other strings, and so on. 
        //If the xth character of the first string doesnt match the xth character of any of the 
        // other strings, then we have found the longest prefix and we return it. 
        //It is also possible for the ther strings to not have an xth character as their size would be smaller so we check that as well. 
        for (int i = 0 ; i<strs[0].size();i++){
            //Through the above loop I am accessing each character of the first string. 
            char c = strs[0][i]; //current character being processed. 
            for (int j = 1; j<strs.size();j++){
                if (i>=strs[j].size() || c!=strs[j][i] /*string j ka ith character*/) //checking for size and equalness. 
                    return strs[0].substr(0,i); 
            }
        }
        return strs[0]; 
    }
};