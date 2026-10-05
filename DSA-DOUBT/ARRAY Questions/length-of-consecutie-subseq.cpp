// Longest Consecutive Subsequence
// Solved
// Difficulty: MediumAccuracy: 33.0%Submissions: 421K+Points: 4Average Time: 25m
// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Examples:

// Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
// Output: 6
// Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
// Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
// Output: 4
// Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.
// Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
// Output: 7
// Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.
// Constraints:

// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 105

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st; 
        int ans = 0; 
        for (int x: arr)
            st.insert(x); 
        for (int x: st){
            if (st.find (x-1) == st.end()){
                //there is no smaller. element (by 1) meaning this current element is a start of a new sequence. 
                int length = 1; 
                int num = x;
                while (st.find(num+1) != st.end()){
                    length++; 
                    num++; 
                }
                ans = max (ans, length); 
                    
            }
            // the curr element is not a start of the sequence and hence 
            // cant be bigger than the sequence it itself is a part of, so we skip this elemnt. 
        }
        return ans; 
        
    }
}; //expected tc was o(n) so we went with the set approach.
// otherwise we could have sorted the array and then counted the longest consecutive sequence.