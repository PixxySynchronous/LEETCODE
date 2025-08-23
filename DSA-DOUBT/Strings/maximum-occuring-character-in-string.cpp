// Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        int frequency[256]={0};
        for (char c : s){
            frequency[c]++;
        }
        int maxfreq=-1;
        int ans=0;
        for(int i=0;i<256;i++){
            if (frequency[i]>maxfreq){
            maxfreq=frequency[i];
            ans = i;}
        }
        return ans;
    }
};

//In hindsight it appears to be a simple question, however since i was not well versed with strings i struggled. i also forgot the logic of keeping the count 
//of an element so instead of jumping right to AI i looked thorugh my previous answers and got the logic of the frequency array
//in this solution the index contains the character and the value contains its frequency 