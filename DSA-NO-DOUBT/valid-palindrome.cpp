//Leetcode 125 A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 


class Solution {
public:
    bool isPalindrome(string s) {
        string filtered; 
        for (char c:s){
            if (isalnum(c))
            filtered+=tolower(c);
        }
        int start=0;
        int end=filtered.size()-1;
        while(start<end){
            if (filtered[start]!=filtered[end])
            return false;
            start++;
            end--;
        }
        return true; 
    }
};