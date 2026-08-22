// Given a array arr[] and positive integer k denoting heights of towers, you have to modify the height of each tower either by increasing or decreasing them by k only once.

// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower. The modified height of the tower can be negative.

// Note: A slight modification of the problem can be found here. 

// Examples:

// Input: arr[] = [1, 5, 8, 10], k = 2
// Output: 5
// Explanation: The array can be modified as [3, 3, 6, 8]. The difference between the largest and the smallest is 8 - 3 = 5.
// Input: arr[] = [3, 9, 12, 16, 20], k = 3
// Output: 11
// Explanation: The array can be modified as [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17 - 6 = 11. 
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // first we sort the array. 
        //Then we choose a splitting point.
        //All indexes behind the splitting point get +k, all infront, including arr[i] get -k. 
        //Since the array is split, we know that the min element would either be
        //arr[0] + k or arr[i] - k.
        //Similarly the max element would be arr[i-1] + k or arr[n-1] - k 
        //The least difference out of all the split points is then taken. 
        sort (arr.begin(), arr.end());
        int n = arr.size();
        int ans = arr[n-1] - arr[0]; //this covers the edge cases of increasing ALL elements of the array,
        //which isnt covered by the loop
       
        for (int i = 1 ; i<arr.size(); i++){
           //negative heights are allowed in this qsn, but if it wasnt:
           //if (arr[i] - k < 0) continue; //smallest possible value in the array,where -k is done. If this si negative,we move to next split. 
            int minVal = min (arr[0] + k, arr[i]-k); //least value in the array after modification. 
            int maxVal = max (arr[i-1] +k , arr[n-1] - k); //max value in the array after modificaiton. 
            ans = min (ans, maxVal - minVal); 
        }
        return ans; 
    }
};