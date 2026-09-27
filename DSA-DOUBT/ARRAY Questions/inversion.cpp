// Count Inversions
// Solved
// Difficulty: MediumAccuracy: 16.93%Submissions: 803K+Points: 4
// Given an array of integers arr[]. You have to find the Inversion Count of the array. Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.
// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.
// Constraints:

// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104
class Solution {
  public:
    void merge (vector<int>&arr, int left, int mid, int right, int& ans){
        vector<int> temp; 
        int i = left ; 
        int j = mid + 1; 
        while (i<=mid && j<=right){
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                // left element is greater than the right so the the number of pairs is
                // equal to all the elements left in the left array plus the element itself 
                ans+= mid - i + 1; 
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining elements from right half
        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }
        // Copy back into original array
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
        
    }
    void mergeSort (vector<int> &arr, int left , int right, int& ans){
        if (left>=right)
            return; 
        int mid = (left + right)/2; 
        mergeSort (arr, left, mid, ans); 
        mergeSort (arr, mid + 1, right, ans);
        merge (arr, left, mid, right, ans); 
    }
    int inversionCount(vector<int> &arr) {
        //Since we need to compare the left side of the array to the right side of the array
        //, we should think about merge sort. Here merge sort gives us a very critical advantage. 
        /* Suppose our left side arr =[2,4] and right side [1,3,5] Now while merging i notice 
        that arr[leftPointer] > arr[rightPointer], this immediataly tells me that total number of pairs 
        which could be formed = all the elements to the right of the leftPointer + the element itself. 
        This is because if 2 is bigger than 1, all the elements to the right of two in the left array 
        are also going to be bigger than 1 as the left array itself is sorted. So we get the pairs 2,1 and 4,1 from 
        just one comparison.
        */
        int ans = 0 ; 
        mergeSort (arr, 0, arr.size()-1, ans); 
        return ans; 
    }
};