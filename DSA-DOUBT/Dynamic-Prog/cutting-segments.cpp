//  Cut Into Segments
// Moderate
// 80/80
// Average time to solve is 25m
// Contributed by
// 95 upvotes
// Asked in companies
// Problem statement
// You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 2
// 7 5 2 2
// 8 3 3 3
// Sample Output 1:
// 2
// 0
// Explanation For Sample Input 1:

// In the first test case, cut it into 2 parts of 5 and 2.

// In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given length. 
// Sample Input 2:
// 2
// 7 3 2 2
// 8 1 4 4
// Sample Output 2:
// 3
// 8
// Explanation For Sample Input 2:
// In the first test case, cut it into 3 parts of 3, 2 and 2.

// In the second case, cut it into 8 parts of length 1.
#include <bits/stdc++.h>
using namespace std;
int solve (int n, int x, int y , int z, vector<int> &dp){
	if (n==0)
		return 0; 
	if (n<0)
		return INT_MIN; //invalid choice
	if (dp[n] != -1)
		return dp[n]; 
	// we have 3 choices to make at eery step. 
	// if we take x, what is the max amount of segments i can get from the remaining rod
	int a = solve (n-x,x,y,z,dp); // max amount of segments i can get from the remaining rod if i take out x
	int b = solve (n-y, x,y,z,dp); // same as above and below
	int c = solve (n-z,x,y,z,dp); //max amounts of segments i can get with the remaining rod if i take out z
	// total segments would be one for the one part we take out and then the max amount I can get from the remaining segments 
	return dp[n]= 1+max(a,max(b,c)); 
}


int cutSegments(int n, int x, int y, int z) {
	// we make a function which returns the max segments for rod of length n
	// int ans = solve (n,x,y,z); 
	// if (ans >= 0)
	// 	return ans; 
	// return 0; 
	vector<int> dp (n+1,-1);
	int ans = solve (n,x,y,z,dp); 
	if (dp[n] <0)
		return 0;
	return dp[n];  
	}

	//memoisation brings tc from o(3^n) to o(n)