// 70. Climbing Stairs
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

class Solution {
public:
    int perm (int n, int currStair, vector<int> & stairs){
        if (currStair == n)
            return 1; 
        if (currStair > n)
            return 0; 
        if (stairs[currStair]!=-1)
            return stairs[currStair]; 
        else
            stairs[currStair] = perm (n,currStair+1,stairs) + perm (n,currStair+2,stairs); 
            return stairs[currStair];
        // number of ways i can go from current stair to last stair is equal to the sum of number of ways i can get to last stair by moving one step and number of ways I can get to last stair by moving 2 stairs.
        //if im on step one i calc steps 2 and step 3. if im on step 2 i calc step 3 and step 4, but step 3 was already calculated, so I need to store that in an array.  
    }
    int climbStairs(int n) {
        int currStair =  0; 
        vector<int> stairs (n,-1);
        return perm (n,currStair,stairs); //this function tells me how many ways i can go from current stair to the last stair. 
    }
};