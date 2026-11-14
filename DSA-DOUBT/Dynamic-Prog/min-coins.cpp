// 322. Coin Change
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
class Solution {
public:
    int solve (vector<int>& coins,  int amount, vector<int> &dp){
        // if amount is 0, it can be obtained in 0 ways
        if (amount == 0)
            return 0; 
        if (amount < 0) // if amount is negative it cant be obtained so we return int max
            return INT_MAX; 
        if (dp[amount]!=-1)
            return dp[amount]; 
        int mini = INT_MAX; 
        // else, to get the least amount of coins to get this amount we will try all the the possible combinations with all the possible coins, i.e at every step, I have n choices to make, n being the size of coins array. So to consider all n choices i use a for loop. 
        for (int i = 0 ; i<coins.size() ; i++){

            int ans = solve (coins, amount - coins[i], dp); // ans to get this particular amount through this choice would be the min nnumber of ways to get amount-coins[i] + 1 (cuz we add coins[i] then).
            // we dont do pplus one here as ans can be impossible, i.e int max and adding one to it causes overflow 
            if (ans != INT_MAX)
            mini = min (ans+1,mini); // we check if this is the option giving us the minimum choice or not. 
            
        }
        return dp[amount] =  mini; // we return the minimum way to get the amount. 
    }
    int coinChange(vector<int>& coins, int amount) {
        // we make a recursive function which will tell us the minimum number of ways to obtain a given amount.
        // we make a 1D array to store the minimum ways to obtain an amount x so that we dont recalculate it. 
        vector<int> dp (amount+1,-1); // possible amounts can be 0,1,2,3,..amounts which is amounts + 1 states 
        int ans =  solve (coins, amount,dp);
        if (ans == INT_MAX)
            return -1; 
        return ans; 

    }
};