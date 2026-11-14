//  Count derangements
// Moderate
// 80/80
// Average time to solve is 35m
// Contributed by
// 115 upvotes
// Asked in companies
// Problem statement
// A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

// Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

// Note:
// The answer could be very large, output answer %(10 ^ 9 + 7).
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 3000

// Time limit: 1 sec
// Sample Input 1:
// 2
// 2
// 3
// Sample Output 1:
// 1
// 2
// Explanation of Sample Output 1:
// In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

// In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements, no element is present at its actual position.

// Sample Input 2:
// 2
// 1
// 4
// Sample Output 2:
// 0
// 9
// Explanation of Sample Output 2:
// In test case 1, For the array = {0}, there is no possible derrangements. Hence the answer is 0 (zero).

// In test case 2, For the array elements = {0, 1, 2, 3}, total 9 derrangements are possible. One of them is: { 3, 2, 1, 0}.

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long solvewithDP(int n, vector<long long>& dp) {

    if (n == 0)
        return 1;

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = ((n-1) * 
        ((solvewithDP(n-1, dp) + solvewithDP(n-2, dp)) % MOD)) % MOD;
}
//this can also be done in sc o(1)
// dp[n] depends on dp[n-1] and dp [n-2]
// so we make prev 2 whihc is = 0 as it reps dp[1]
// then we ake prev 1 which is = 1 as it reps dp[2]
// then ans = prev1 + prev 2
// then prev2 = prev 1
// prev 1 = ans
// so that we move ahead the imaginary array
// this way no dp array is required hence sc o(1)
long long int countDerangements(int n) {
    // if i have an array of size n+1 with elements 0,1,2,3,4,5,6,....n. 
    // I want the 0th index to not be at oth place so I move it to ith index. 
    // ith index will have the number i which needs to go to a new place. 
    // this place can be 
    // 1. the 0th index itself. Which means now i have n-2 positions with n-2 elements which
    // need to rearranged, hence we have reduced the problem to f(n-2). n-2 as 0th and ith index have been swapped. 
    // 2. the 0 takes ith index and i doesnt go anywhere. meaning i have n-1 elements which needs to go to n-1 indexs
    // this means we have shortened the problem to f(n-1). 
    // this means total number of permutations if i move 0 to ith index is 
    // (n-1)*(remaining subproblem) where remaining subproblem ans is (f(n-2)+f(n-1))
    // n-1 indicates all the possible ith indexes 0 can go to 
    // //base case
    // if (n==1)
    //     return 0; 
    // if (n==2)
    //     return 1; 
    // int ans = (n-1)*( countDerangements(n-1) +  countDerangements(n-2));
    // return ans%1000000007; 
    vector<long long > dp (n+1,-1); 
    int ans = solvewithDP (n,dp); 
    return ans%1000000007;
}