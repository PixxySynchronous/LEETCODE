//Leetcode 443 Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

// Note: The characters in the array beyond the returned length do not matter and should be ignored.

class Solution {
public:
    int compress(vector<char>& chars) {
        vector <char> s ; 
        int counter = 1 ; // number of occurences of that element is initially 1. 
        char current; // current character being processed. 
        if (chars.size()==1) // edge case 
            return 1; 
        for (int i = 0 ; i<= chars.size() - 1 ; i+=counter){ //<= char.size() -1 as im accessing k+1 ,incrementing by counter. 
            counter = 1; 
            current = chars [i] ;
            int k = i ;  //i points to the first element of the group while k increments to the end of the group
            while (chars[k]==chars[k+1]){
                counter ++ ;
                k++;
                if (k==chars.size()-1)
                break; 
            } 
            if (counter == 1)
                s.push_back(current); 
            else{
                s.push_back(current);
                string count = to_string(counter);
                for (char c : count )
                s.push_back (c);
            }
        }
        chars.clear();
        for (int i = 0 ; i < s.size() ; i++ ){
            chars.push_back(s[i]);
        }
           
    
        return chars.size(); 
    }
};

//I could do everything on my own just got stuck in the pushing of counter > 99 . Simple solution provided
//by Gpt was to conver it into string by to_string(counter) and push that down. Also if a number is to be stored as a char add + '0 next to it. 