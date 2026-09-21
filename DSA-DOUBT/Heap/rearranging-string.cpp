// 767. Reorganize String
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
class Solution {
public:
    class elem {
        public:
            int freq; 
            char c; 
            elem (char c, int freq){
                this->c= c;
                this->freq = freq; 
            }
    }; 
    class compare {
        public:
            bool operator ()(elem a , elem b){
                return a.freq<b.freq; 
            }
    }; 
    string reorganizeString(string s) {
        //Thinking:

        /* See we cant have 2 adjacent elements. If there are for say a frequency of k a's. We need atleast k-1 frequency of other characters to be placed in between them. 
        Eg) a,_,a_,a -> if 3 a's are present we need atleast 3-1=2 other characters to be placed in between them. What we can do is, have a frequency count of all the elements in the string. Then I place the most frequent element in the output. Next to it, the next mostfrequent element should be placed. IF the next frequency element is still the current element eg) a=5,b=1 -> curr = a which makes freq arr a=4,b=1, a is still the next most freq element, I look for a separate element with the second most freq. Which is b in this case. If this second element doesnt exist, we know making a string is not possible. 
        */

        /* To keep the frequncy and then getting the next nearest frequency etc. , I can use maxHeap.*/
        priority_queue<elem ,vector<elem>,compare> maxHeap; 

        //Need initial frequency mapping into the maxHeap. 
        int freq[26] = {0}; 
        for (char k : s){
            freq[k - 'a']++;
        }

        for (int i = 0 ; i<26 ; i++){
            if (freq[i] != 0){
                elem curr ('a'+i, freq[i]);
                maxHeap.push(curr); 
            }
        }

        string ans = ""; 
        char prev = '#'; 
        
        while (!maxHeap.empty()){
            elem curr = maxHeap.top(); 
            maxHeap.pop(); 
            if (curr.c == prev){
                if (maxHeap.empty()) return ""; //No second most recurring element exists hence string cant be made. 
                else{
                    elem next = maxHeap.top(); //next most occuring elem
                    maxHeap.pop(); 
                    ans.push_back(next.c); 
                    prev = next.c; 
                    next.freq--; 
                    if (next.freq>0) //only if the freq is still there do we reinsert. 
                        maxHeap.push(next); 
                    maxHeap.push(curr); //reinsert the most freq char. 
                    continue;    
                    }
                
            }
            else{
                ans.push_back (curr.c); 
                prev = curr.c; 
                curr.freq -- ; 
                if (curr.freq>0)
                    maxHeap.push(curr); 
            }
            
        }
        return ans; 

    }
};