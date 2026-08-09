// Longest Substring Without Repeating Characters
// Medium
// Topics
// Company Tags
// Hints
// Given a string s, find the length of the longest substring without duplicate characters.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: s = "zxyzxyz"

// Output: 3
// Explanation: The string "xyz" is the longest without duplicate characters.

// Example 2:

// Input: s = "xxxx"

// Output: 1
// Constraints:

// 0 <= s.length <= 1000
// s may consist of printable ASCII characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> freq; 
        int i = 0 ; 
        int j = 0 ; 
        int maxSize = 0; 
        while (j<s.size()){
            freq[s[j]]++; //add curr elem in freq. 
            while (freq[s[j]]>1){ //if adding the current elem makes it NOT UNIQUE,
            //we remove an element from the back till adding the curr elem makes it unique in the window. 
                freq[s[i]] -- ;
                i++; 
            }
            //else we have an unique valid window. 
            maxSize = max (maxSize, j-i+1); 
            j++;
        }
        return maxSize; 
    }
};
