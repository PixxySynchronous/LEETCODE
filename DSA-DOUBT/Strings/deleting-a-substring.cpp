//Leetcode 1910    Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.size()!=0 && s.find(part)<= s.size()){
            s.erase(s.find(part), part.length());
        }
    return s;
    }
};
//DIDNT KNOW THE METHODS AND THERFORE COULDN'T DO THE QUESTION.IF .find() METHOD FAILS, IT RETURNS NPOS
//WHICH IS A VERY BIG VALUE AND HENCE THE ABOVE CONDITION IN WHILE LOOP PRESENT. 