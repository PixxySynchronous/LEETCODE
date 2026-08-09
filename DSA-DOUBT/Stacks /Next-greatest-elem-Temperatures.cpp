// Daily Temperatures
// Medium
// Topics
// Company Tags
// Hints
// You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

// Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

// Example 1:

// Input: temperatures = [30,38,30,36,35,40,28]

// Output: [1,4,1,2,1,0,0]
// Example 2:

// Input: temperatures = [22,21,20]

// Output: [0,0,0]
// Constraints:

// 1 <= temperatures.length <= 1000.
// 1 <= temperatures[i] <= 100
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Approach is to store the index of all the elements whos next greater element
        //hasnt been found yet. So we traverse the array. If array element is greater than 
        //st.top() then the index currently at top of stack has found its next greatest element 
        //so we note that and now we pop that index from the stack. 
        //In this question we need the number of days so we do index of array element and st.top()
        stack<int> st; 
        st.push(0); //first we have index 0. 
        int n = temperatures.size(); 
        vector<int> ans (n,0); //initialising important as we need to access index of this vector. 
        for (int i = 1; i<temperatures.size(); i++){
            while (!st.empty() && temperatures[i] > temperatures[st.top()]){ // we use while loop as sice the top got updated, the current element at i might be the next greatest element for the next top element. 
                ans[st.top()] = i-st.top(); //st.top() has the index, not the value. 
                st.pop(); 
            }
            st.push(i); //if stack is empty or the current element is smaller than the top then we simply push. 
        }
        return ans; 
    }
};
