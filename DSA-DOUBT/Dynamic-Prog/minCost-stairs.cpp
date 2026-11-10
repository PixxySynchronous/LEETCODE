// 746. Min Cost Climbing Stairs
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase.

// Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the staircase, which is the position just past the last step (index cost.length).

 

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
class Solution {
public:
    int minCost (vector<int>& cost, int n, vector<int> & dp){
        if (n==0) //mincost to reach this stair is the stair itself only as we can just start from here
            return cost[0]; 
        if (n==1)
            return cost [1]; 
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = cost[n] + min(minCost(cost, n-1, dp),minCost(cost, n-2, dp));
        //mincost to reach a stair which isnt the top is the minimum of the starting points plus the cost of the stair itself. 

    }
    int minCostClimbingStairs(vector<int>& cost) {
        //min cost to reach a step would be the min(cost of n-1, cost of n-2) + cost[n]. 
        //so we make a fucntion which returns the min cost to reach the stair. 
        // Once we reach the top we dont need to add the cost of the top stair itself as we are not jumping anywhere from it, so the way to reach the top stair would be either coming through the last or the second last step. 
        int n = cost.size(); 
        vector<int> dp (n,-1); 
        return min(minCost(cost, n-1,dp),minCost(cost, n-2,dp));
    }
    
};