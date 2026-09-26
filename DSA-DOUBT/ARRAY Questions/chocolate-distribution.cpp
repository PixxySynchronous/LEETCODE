// Chocolate Distribution Problem
// Difficulty: EasyAccuracy: 49.91%Submissions: 292K+Points: 2Average Time: 15m
// Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that:

// Each student gets exactly one packet.
// The difference between maximum number of chocolates given to a student and minimum number is minimum and return that minimum possible difference.
// Examples:

// Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
// Output: 6
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing m packets as [3, 4, 9, 7, 9].
// Input: arr = [7, 3, 2, 4, 9, 12, 56], m = 3
// Output: 2
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing m packets as [3, 2, 4].
// Input: arr = [3, 4, 1, 9, 56], m = 5
// Output: 55
// Explanation: With 5 packets for 5 students, each student will receive one packet, so the difference is 56 - 1 = 55.

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort (a.begin(), a.end()); //since we need to minimize the difference, 
        // we need to bring similar (numvers close to each other) together. 
        //so we sort. 
        int i = 0 ; 
        int j = m-1; //end of the window.
        int minDiff = INT_MAX;
        while (j<a.size()){
            int diff = a[j]-a[i]; 
            minDiff = min (minDiff, diff); 
            j++; 
            i++; 
        }
        return minDiff; 
        
    }
};