// 11. Container With Most Water
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j= heights.size()-1; 
        int area = 0;
        while (i<j){
            int length = min(heights[i],heights[j]);
            int width = j-i;
            int newArea = length*width; 
            area = max(area, newArea); 
            if (heights[i] <= heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return area;
    }
};
//To calculate area between 2 lines, width will always be j-i. 
//Need to see 2 lines so can use 2 pointer approach, starting from the two extremes and then
//moving in from the side with the smaller length (in the hopes of getting a bigger length).