// Leetcode-852 You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0 ;
        int end = arr.size()-1;
        int mid = s + (end-s) /2;
        while ( s < end){
            if (arr[mid] < arr[mid+1]){
                s= mid +1; 
            }
            else 
            end = mid; 
            mid = s + (end-s) /2;
        }
        return mid; 
    }
};

