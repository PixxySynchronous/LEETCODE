// 567. Permutation in String
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.


class Solution {   
public:
    bool Equals (int a[],int b[]){
        int i = 0;
        while ( i < 26){
            if (a[i]!=b[i])
            return 0;
            i++;
        }
        return 1; 
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length()>s2.length())
        return 0; 
        int counter1 [26] = {0};
        for (int i =0 ; i<s1.length() ; i++){
            int index = s1[i] - 'a';
            counter1[index]++;
        }
        int workspace = s1.length();
        int counter2[26] = {0};
        //Marking first window (sub-array to be inspected)
        for (int i = 0 ; i < workspace ; i ++ ){
            int index = s2[i] - 'a';
            counter2[index]++;
        }

        if (Equals(counter1,counter2))
        return 1;
        //Shifting window logic. If window = 3 , we have checked for index 0 ,1,2 so now we start from 3.
        int i = workspace ; 

        while (i<s2.length()){
            char newChar = s2[i];
            counter2[newChar - 'a']++;
            char oldChar = s2[i - workspace]  ; 
            counter2[oldChar - 'a']--;
            if (Equals(counter1,counter2))
            return 1;
            i++;
        }
        return 0; 
    }
};

 //Couldnt solve this question with my own logic so took the help of the video. The concept of workspace is now understood and is also noted down. An initial window is made and compared, if it doenst match, to move the wnidow, we add a new character and take out the old character. 