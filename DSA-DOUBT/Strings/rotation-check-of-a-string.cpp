// String Rotation Check
// Solved
// Difficulty: MediumAccuracy: 43.83%Submissions: 375K+Points: 4Average Time: 15m
// You are given two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.

// Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them.

// Examples :

// Input: s1 = "abcd", s2 = "cdab"
// Output: true
// Explanation: After 2 right rotations, s1 will become equal to s2.
// Input: s1 = "aab", s2 = "aba"
// Output: true
// Explanation: After 1 left rotation, s1 will become equal to s2.
// Input: s1 = "abcd", s2 = "acbd"
// Output: false
// Explanation: Strings are not rotations of each other.
// Constraints:

// 1 ≤ s1.size(), s2.size() ≤ 105
// s1 consists only of lowercase English alphabets
// s2 consists only of lowercase English alphabets

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // All possible rotations of a string reside in the common string of s1+s1. 
        // So if s2 is a substring of s1+s1 we know it is a valid rotation. 
        if ((s1+s1).find(s2) == string::npos)
            return false; 
        return true; 
        
    }
    //.find() is also o(n2) worst case as it uses sliding window technique to find the substring. 
};