// Encode and Decode Strings
// Medium
// Topics
// Company Tags
// Hints
// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

// Machine 1 (sender) has the function:

// String encode(List<String> strs) {
//     // ... your code
//     return encoded_string;
// }
// Machine 2 (receiver) has the function:

// List<String> decode(String encoded_string) {
//     // ... your code
//     return decoded_strs;
// }
// So Machine 1 does:

// String encoded_string = encode(strs);
// and Machine 2 does:

// List<String> decoded_strs = decode(encoded_string);
// decoded_strs in Machine 2 should be the same as the input strs in Machine 1.

// Implement the encode and decode methods.

// Example 1:

// Input: strs = ["Hello","World"]

// Output: ["Hello","World"]
// Explanation:

// Solution solution = new Solution();
// String encoded_string = solution.encode(strs);

// // Machine 1 ---encoded_string---> Machine 2

// List<String> decoded_strs = solution.decode(encoded_string);

// Example 2:

// Input: strs = [""]

// Output: [""]

// Constraints:

// 0 <= strs.length < 100
// 0 <= strs[i].length < 200
// strs[i] contains any possible characters out of 256 valid ASCII characters.
class Solution {
public:

    string encode(vector<string>& strs) {
        string encode; 
        // so basically if we have a vector of strings like "hi","hello",
        // I need to make it into one string and return that string as encoded string. 
        // However I need to make it in such a way that I can recognize where one string starts
        // and ends, so that it is possible for me to decode it back to a vector of strings. 
        //Approach is to encode strings like this: {"hi","hello"} -> {2#hi5#hello}
        for (string x: strs){
        int length = x.size();
        encode.append(to_string(length));
        encode.push_back('#');
        encode.append(x);
        }
        return encode; 

    }

    vector<string> decode(string s) {
       int len = 0; 
       int i =0;
       int j =0; 
       vector<string> ans; 
       while (i < s.size()){ 
            int j = i; 
            while (s[j]!='#'){  //build up digits of the length till we encounter a #
            len = (len*10) + (s[j] - '0'); 
            j++;
            } //j points to #, so we need to access one letter from that. 
            ans.push_back(s.substr(j+1,len));
            i = j + 1 + len; // j + 1 is the start of the current string.
            // Adding len moves i to the beginning of the next encoded string.
            len = 0; //length of new word is currently unknown hence 0. 
          
       }
       return ans; 


    }
};
