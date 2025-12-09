// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]







class Solution {
public:
    void solve (string digits, string output, vector <string> &ans, int index, string mapping[]){
        if (index>= digits.size()){
            ans.push_back(output);
            return; 
        }
        int number = digits [index] - '0'; 
        string value = mapping[number]; 
        for (int i = 0 ; i< value.length(); i++){
            output.push_back(value[i]); 
            solve (digits,output,ans,index+1,mapping);
            output.pop_back(); 
        }

    }
    vector<string> letterCombinations(string digits) {
        string output = "";
        vector <string> ans ; 
        int index =0 ; 
        string mapping [10] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        solve (digits, output, ans, index, mapping);
        return ans; 
    }
};

//this code is similar to the powerset code where we are making a state space tree of backtracking
//where in each level we are making branches for each character mapped to the digit at that index.
//I couldnt think of the mapping part initially but rest all was similar to the powerset code.