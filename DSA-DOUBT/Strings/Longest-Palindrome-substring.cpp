// 5. Longest Palindromic Substring
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s; 
        //Method is to consider each and every element as a center (but that only covers odd length palindromes, for even length palindromes,we consider the current element and the element next to it as center)
        string res = "";
        for (int i =0 ; i<s.size(); i++){
            int currentLength = 0; 
            int l = i; 
            int r = i; 
            while (l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }//note: after while loop, left has gone one behind the vlaid palindrome and right has gone one ahead. 
            currentLength = r-l-1; //current length = r - 1 - (l+1) + 1 (as 0 indexing)
            if (currentLength>res.size()){
                res = s.substr(l+1, currentLength); 
            }
            //same for even palindromes. Just 2 elements as center. 
            l=i;
            r=i+1; 
            while (l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            currentLength = r-l-1;
            if (currentLength>res.size()){
                res = s.substr(l+1, currentLength); 
            }
        }
        return res; 
    }
};