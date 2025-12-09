// LEETCODE 88 You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int currentm=0; //keeps tab of num1 array
        int currentn=0; //keeps tab of num2 array
        int index=0; //keeps tracks of num1 index
        vector<int> temp (nums1);  
        while (currentm<m && currentn<n){
            // if (temp[currentm]==0){
            // break;
            // }
            if (temp[currentm]<nums2[currentn]){
                nums1[index]=temp[currentm];
                currentm++;
                index++;
            }
            else {
                   nums1[index]=nums2[currentn];   
                   currentn++;
                   index++;
            }
        }
       while (currentn<n){
        nums1[index]=nums2[currentn];
        currentn++;
        index++;
       }
       while (currentm<m){
        nums1[index]=temp[currentm];
        currentm++;
        index++;
       }
    }
};


//I came up with this solution on my own. The logi is simple ... 2 separate counters for 2 separate arrays. While it took me time to iron it out, i did do it on my own. Since here the time complexity is O(m+n) ,we are good. However since space complexity is o(m) due to the temp vector, we know we can do better so i asked AI. 
//For future attempts: since numsi is m+n size, what we can do is start merging from the last array , i.e biggest elements first.  Try it. 