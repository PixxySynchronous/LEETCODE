// Zero Sum Subarray
// Solved
// Difficulty: MediumAccuracy: 39.79%Submissions: 330K+Points: 4Average Time: 20m
// Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. 

// Examples:

// Input: arr[] = [4, 2, -3, 1, 6]
// Output: true
// Explanation: 2, -3, 1 is the subarray with a sum of 0.
// Input: arr = [4, 2, 0, 1, 6]
// Output: true
// Explanation: 0 is one of the elements in the array so there exist a subarray with sum 0.
// Input: arr = [1, 2, -1]
// Output: false
// Constraints:

// 1 ≤ arr.size() ≤ 105
// -105 ≤ arr[i] ≤ 105
class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        // When we do the brute force, we repeatedly calculate the 
        /* sum of the previous elements. eg) 4+2-3+1+6 then 2-3+1+6 
        this can be stored in prefix sum. 
        The key thing to note here is that prefix sum can increase and decreaser
        as elements can be positive or negative. So if we encounter a prefix sum again. 
        All the elements  in between sum upto 0. 
        */
        int prefix = 0; 
        unordered_set<int> st; //stores all the prefixes. 
        st.insert(0); //prefix before the array starts is 0. Or prefix for arr[0]  
     
        for (int i = 1; i<arr.size() ; i++){
            prefix += arr[i-1]; 
            if (st.find(prefix) != st.end())
                return true; 
            st.insert(prefix);
        }
        return false; 
        
    }
};