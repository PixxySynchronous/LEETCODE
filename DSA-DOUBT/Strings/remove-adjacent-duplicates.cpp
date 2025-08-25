//Leetcode 1047 You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

class Solution {
public:
    string removeDuplicates(string s) {
        for (int i = 0 ; i < s.length() -1 ; i++){
            if (s.empty())
            return s; 
            if (s[i]==s[i+1]){
                s.erase(i,2); 
                i = -1; 
            }

        }
        return s; 

    }
};

//i iwll be reinitialed to -1 and not 0 because it gets incremented again once the loop ends. Also couldn't figure out the border case of if string is empty . Asked the logic from gpt, coded it myself. 
//much better solution with stacks is present but i havent covered that yet. 