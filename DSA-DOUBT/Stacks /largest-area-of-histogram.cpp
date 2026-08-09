// LEETCODE 84 
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
class Solution {
    //Approach written in the main function. 
public:
    vector<int> previousSmallElem(vector<int>& heights){
        //if top is greater, while top is greater you pop the stack, else you push. 
        //stack holds the index.
        stack<int> st; 
        vector<int> ans; 
        st.push(-1); 
        for (int i =0 ; i<heights.size(); i++){
            while(st.top()!= -1 && heights[st.top()]>=heights[i]){
                    st.pop(); 
            }
            ans.push_back(st.top()); 
            st.push(i);
            }
        return ans; 
    }

    vector<int> nextSmallElem(vector<int>heights){
        //starting from the end of the array, while stack.top() is >= element, pop, else push. 
        stack<int> st; 
        vector<int> ans; 
        st.push(-1); 
        for (int i = heights.size()-1; i>=0; i--){
            while (st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i); 
        }
        reverse (ans.begin(), ans.end());
        return ans; 
        //reversing can be avoided if we simply just initialise the ans vector.
    }
       

    
    int largestRectangleArea(vector<int>& heights) {
        //So given a rectangle, you can expand its width until an element 
        //lesser than the element we are on is met. And expansion of the width
        //can happen in both left and right directions, so, all we need is the 
        //next smallest element, the previous smallest element, and then subtract 
        //their indices to get the total width of the rectangle. Height would be the 
        //same as the height of the element we are currently on. 
        vector<int> nextSmall = nextSmallElem(heights);
        vector<int> prevSmall = previousSmallElem(heights); 
        int maxArea = 0; 
        for (int i = 0 ; i<heights.size(); i++){
            //if there is no nextSmallest element, then the vector contains -1, however
            //for our qsn, this means we can extend the boundary of the width till the end of the vector.. 
            //so the boundary itself becomes heights.size(). Similarly, if there is no previous small element, 
            //we are returning -1, which works as the boundary being at -1 means we can expand till index 0, starting of 
            //the array. 
            if (nextSmall[i] == -1){
                int area = (heights.size() - prevSmall[i] - 1)*heights[i]; 
                maxArea = max(maxArea, area);
            }
            else {
                int area = (nextSmall[i] - prevSmall[i] - 1)*heights[i];
                maxArea = max(maxArea, area);
            } 
           
        }
        return maxArea; 
    }
};
