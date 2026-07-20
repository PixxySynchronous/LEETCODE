class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s; 
        //Method is to consider each and every element as a center (but that only covers odd length palindromes, for even length palindromes,we consider the current element and the element next to it as center)
        string res = "";
        int start = 0;
        int maxLength = 1; 
        for (int i =0 ; i<s.size(); i++){
            int currentLength = 0; 
            int l = i; 
            int r = i; 
            while (l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }//note: after while loop, left has gone one behind the vlaid palindrome and right has gone one ahead. 
            currentLength = r-l-1; //current length = r - 1 - (l+1) + 1 (as 0 indexing)
            if (currentLength>res.size()){
                 start = l+1;
                 maxLength = currentLength;
            }
            //same for even palindromes. Just 2 elements as center. 
            l=i;
            r=i+1; 
            while (l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            currentLength = r-l-1;
            if (currentLength>res.size()){
                start = l+1;
                maxLength = currentLength;
            }
            res = s.substr(start, maxLength); 
        }
        return res; 
    }
};