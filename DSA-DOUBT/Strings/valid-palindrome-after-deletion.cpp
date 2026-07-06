// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
class Solution {
public:
    bool helper (string s, int start, int end){
        while (start<end){
            if (s[start]!=s[end]){
                return false;
            }
            start++;
            end--; 
        }
        return true; 
    }
    bool validPalindrome(string s) {
        int i = 0; 
        int j = s.size()-1; 
        while (i<j){
            if (s[i]!=s[j]){
           
                    //if both the pointers are not the same, then we must delete either one to get a valid palindrome
                    //and if we dont, for both the cases, then we return false. 
                    if (helper(s, i+1, j)){
                        return true; //helper has checke the remaining string already.  
                    }
                    
                    if (helper(s, i, j-1)){
                        return true;
                    }
                    else return false; 
                
            }
            else{
                i++;
                j--;
            }
        }
        return true; 
    }
};