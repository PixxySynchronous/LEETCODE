// 242. Valid Anagram
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int freq[26] = {0};
        for(char c:s){
            freq[tolower(c)-'a']++;
        }
        for(char c:t){
            freq[tolower(c)-'a']--;
        }
        for(int i: freq){
            if(i!=0)
            return false;
        }
        return true; 


    }
    //if any character can be used, including digits and special chars, then initiate freq as [256]. Above we do -a so that ASCII values of all alphabets lie in between 0-26. If we use an array of 256, -a isnt reqwuired and we can write freq[(unsigned) c], itll directly convert char into number  
};