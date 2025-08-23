// Leetcode-852 You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

int findpeak(vector<int>& arr){
    int s=0;
    int e=arr.size()-1;
    int ans = 0;
    int mid =(s + (e-s)/2);
    while (s<=e){
        if (mid > 0 && mid < arr.size() - 1 && arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            ans=mid;
            break;  
        }
        else if (mid > 0 && arr[mid-1]>arr[mid]){
            e=mid-1;
        }
        else if (mid < arr.size() - 1 && arr[mid+1]>arr[mid]){
            s=mid+1; 
        }
        mid = (s +(e-s)/2); 
    }
    return ans; 
}

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    int ans = findpeak( arr);
    return ans; 
        
    }
};

//the whole solution was thought of by me. Since i knew, however, to use binary search, it made the time complexity constraint practically useless. I needed help with the out of bounds cases via gpt as i did not think of them myself. ANd also the break line was essential as at that time we had already found the answer. That too was given by gpt.