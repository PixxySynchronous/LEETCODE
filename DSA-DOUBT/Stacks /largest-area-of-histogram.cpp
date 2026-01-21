// LEETCODE 84 
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
class Solution {
public:
    vector <int> nextSmallElement ( vector <int> heights){
        int size = heights.size(); 
        vector <int> ans; 
        stack<int> st; 
        st.push(-1); 
        for (int i = size - 1 ; i >= 0 ; i --){
            while (st.top()!= -1 && heights [st.top()] >= heights[i])
                st.pop(); 
            ans.push_back(st.top()); 
            st.push (i); 
        }
        reverse (ans.begin() ,ans.end()); 
        return ans; 
    }
    //store index of next smaller element

    vector <int> prevSmallElement (vector <int> heights){ 
        int size = heights.size(); 
        stack <int> st; 
        vector<int> ans; 
        st.push(-1); 
        for (int i = 0 ; i < size ; i++){
            while (st.top()!= -1 && heights[st.top()] >= heights[i]){
                st.pop(); 
            }
            ans.push_back (st.top()); 
            st.push(i); 
        }
        return ans; 
    }
    //store index of prev smaller element. 
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallElement (heights); //stores the index of the next small elemnt. 
        //if == -1 then all the elements to the right are bigger than the current element and hence the
        //bar can extend till the end of the array. 
        vector <int> prev = prevSmallElement (heights); 
        int size = heights.size(); 
        int maxArea = 0 ; 
        for (int i= 0 ; i< heights.size() ; i++){
            int p = next [i] ;
            if(p == -1) p = size; //(not size -1 as p is not included. valid bar is from q+1 to p-1)
            int q = prev [i] ; 
            int length = p-q-1 ; // (prev[i] + 1)  to  (next[i] - 1) are the allowed indices (we dont include prev and next) and number of integers between them = L-R+1 ,replace this in that formula u get the p-q-1

            int area = heights[i]*length; 
            maxArea = max (area,maxArea); 
        }
        return maxArea; 

    }
};