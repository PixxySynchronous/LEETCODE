// 49. Group Anagrams
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

 

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> mp; // need a data structure to store the 
        // frequency array of each word. Since frequency array itself cant be used as a key, I will turn the frequency array to a string and use it as a key. We need to separate each entry with a character or else the frequency array {11,1} would be same as the array {1,11} (as both would become string 111)
        vector<vector<string>> ans; 
        vector<string> set; 
        for (const string &s: strs){ //avoids copying string, uses the original string
            int freq[26] = {0};
            string freqs = "#";
            for (char c: s){ 
                freq [c - 'a']++;
            }
            for (const int& i: freq){
                freqs+='#'+to_string(i);
            }
            mp[freqs].push_back(s);
        }
        for (const auto &i:mp){
            set = i.second;
            ans.push_back(set);
        }
    
        return ans; 
            
    }
    
};