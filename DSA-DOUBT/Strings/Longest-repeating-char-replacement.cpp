// 424. Longest Repeating Character Replacement
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

class Solution {
public:
    int characterReplacement(string s, int k) {
        //Approach is that of a sliding window, but a bit more complex. We can exchange k characters.
        // It is obvious that we will not exchange the character which has the highest frequency in the current window. 
        //So to decide the number of replacements required in the current window, itll be window size - max freq, as the differnece tells us the differnet characters which are present in the window. 
        //If this difference is greater than k, then the window is invalid and we willneed to shrink it till it becomes valid again. Else, the window is valid and its size is stored. 
        int right = 0 ; 
        int left = 0 ; 
        int maxFreq = 0;
        int res = 0 ; 
        unordered_map <char, int> mp; 
        while (right< s.size()){
            mp[s[right]]++;
            maxFreq = max(maxFreq,mp[s[right]]); //How to keep track of the alphabet with the maxfrequency. 
            if ((right-left+1) - maxFreq <=k){
                res = max(res, right-left+1);
            }
            else{
                while((right-left+1) - maxFreq > k){
                    mp[s[left]]--;
                    left++;
                } 
            }
            right++; //done at the end. 

        }
        return res; 
    }
};