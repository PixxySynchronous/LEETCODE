// Trapping Rain Water
// Hard
// Topics
// Company Tags
// Hints
// You are given an array of non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.

// Return the maximum area of water that can be trapped between the bars.

// Example 1:



// Input: height = [0,2,0,3,1,0,1,3,2,1]

// Output: 9
class Solution {
public:
    int trap(vector<int>& height) {
        //a block of water can stay above any position in the array as long as there is a left
        // and a right boundary. The height of such a block of water would be the min(max(left side, right side))
        // - h[i]. If the difference is negative or 0, no water can be stored on it. If positive, the value tells how
        // many water blocks can be stored. 
        // We will require the knowledge of max bars to the left and right side of h[i], which we can find via prefix
        // and suffix arrays. 
        int n = height.size(); 
        vector<int> prefix (n);
        int maxHeight = height[0]; //for loop below starts from i=1, so for that, maxHeight(to the left) should be first element. 
        prefix[0] = 0; //Left side of the first element is 0 as no boundary exists. 
         for (int i = 1; i<height.size(); i++){
            prefix[i]= maxHeight;
            maxHeight = max(maxHeight, height[i]); 
        }
        int water = 0; 
        int maxRheight = 0;  
        for (int i = n-1; i>=0; i--){
            if(min(prefix[i],maxRheight) - height[i]>0){
                water += (min(prefix[i],maxRheight) - height[i]); //we dont want to add negative water so if condition necessary. 
            }
            maxRheight = max(maxRheight, height[i]);
        }
        return water; 
    }
    // can be done in o(1) tc and sc with the folowing algo:
    //     Algorithm
    // Set two pointers:
    // l at the start
    // r at the end
    // Track leftMax and rightMax as the tallest walls seen.
    // While l < r:
    // If leftMax < rightMax:
    // Move l right.
    // Update leftMax.
    // Add leftMax - height[l] to the result.
    // Else:
    // Move r left.
    // Update rightMax.
    // Add rightMax - height[r] to the result.
    // Return the total trapped water.
};

