// 290. Word Pattern
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.
 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"

// Output: true

// Explanation:

// The bijection can be established as:

// 'a' maps to "dog".
// 'b' maps to "cat".

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp; // pattern maps to string words.
        unordered_map<string, char> rev; // words mapping to characters. 
        //both are required. 
        int i = 0; int j = 0; int words = 0; 
        while (i<pattern.size() && j<s.size()){
            // j is start of word. endOfWord points to the space between words. therefore ends-j gives size of word. 
            int endOfWord = j; 
            while (endOfWord < s.size() && s[endOfWord] != ' '){
                endOfWord++; 
            }
            string word = s.substr(j,endOfWord-j); //substring starting from j, of size end-j. 
            words++; 
            if (mp.find(pattern[i]) == mp.end()){
                mp[pattern[i]] = word; 
            }
            else if (mp[pattern[i]] != word)
                return false; 
            if (rev.find(word) == rev.end())
                rev[word] = pattern[i]; 
            else if (rev [word] != pattern[i])
                return false; 
            i++; 
            j=endOfWord+1; 
        }
        if ( i!= pattern.size() ) //if i is not at the end of its string we have unequal amounts of char -> words mapping so false. This means we have a word with no pattern char. 
            return false; 
        if (j!= s.size()+1) // j goes to end+1 so it should end at s.size()+1. 
            return false; 
        return true;
    }
};
