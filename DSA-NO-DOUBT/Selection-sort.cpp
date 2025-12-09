#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    int smallest=0;
    int j=0;
    for (int i=0;i<n-1;i++){
        j=i+1;
        smallest=i;
        for (;j<n;j++){
            if(arr[j]<arr[smallest]){
            smallest=j; }}
        swap(arr[i],arr[smallest]);
    }
}


//Explanation:
// In this implementation of selection sort, we iterate through the array and for each position, we find the smallest element in the remaining unsorted portion of the array. We then swap this smallest element with the element at the current position. This process is repeated until the entire array is sorted.Since the last element will already be in its correct position, we only need to iterate until n-1. The time complexity of this algorithm is O(n^2) due to the nested loops, making it less efficient for large arrays compared to more advanced sorting algorithms like quicksort or mergesort.

// IMP: store the index not the value in the smallest variable as swap function requires 2 array elements not variables.