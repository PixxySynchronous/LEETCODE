//LEETCODE -4 Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int pointer1=0;
        int pointer2=0;
        int n=nums1.size();
        int m= nums2.size();
        vector <int> sortedarray; 
        while (pointer1<n&&pointer2<m){
            if(nums1[pointer1]<=nums2[pointer2]){
                sortedarray.push_back(nums1[pointer1]);
                pointer1++;
            }
            else {
                sortedarray.push_back(nums2[pointer2]);
                pointer2++;
            }
        }
        while (pointer1<n){
            sortedarray.push_back(nums1[pointer1]); 
            pointer1++;
        } 
        while (pointer2<m){
            sortedarray.push_back(nums2[pointer2]); 
            pointer2++;
        }
        double medianindex = (sortedarray.size()+1)/2.0;
        if (sortedarray.size()%2!=0)
        return sortedarray[medianindex-1];
        else{
            medianindex+=0.5;
            return ((sortedarray[medianindex-1]+sortedarray[medianindex-2])/2.0);
        }
        

    
    }
};

//THE ONLY ISSUE I HAD WAS TO MAKE SURE DIVISION IS DOUBLE WE NEED TO DIVIDE BY 2.0 NOT 2. 