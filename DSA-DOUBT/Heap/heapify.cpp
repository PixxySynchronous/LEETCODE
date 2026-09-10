
// Problem
// Submissions
// Hints & solutions
// Discuss
//  Build Min Heap
// Moderate
// 80/80
// Average time to solve is 30m
// Contributed by
// 88 upvotes
// Asked in companies
// Problem statement
// You are given an array 'ARR' of integers having 'N' elements. Your task is to convert the input array into a min-Binary Heap.

// A min-Binary heap is a complete binary tree in which the value of each internal node is smaller than or equal to the values of the children of that node.

// Note :
// 1. Input array follows 0 - based indexing. 

// 2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.

// 3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 2)-th index if it exists.

// 4. Note that you do not need to create a tree, just update the array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 10
// 1 <= N <= 10^4
// -10^9 <= ARR[i] <= 10^9

// Where 'ARR[i]' denotes the 'i-th' element of the array 'ARR'.

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 5
// 9 3 2 6 7 
// 4
// 1 3 2 4
// Sample Output 1 :
// 1
// 1
// Explanation For Sample Input 1 :
// For the first test case:
// One possible min-heap representation of the input array is the array [ 2, 3, 6, 7, 9 ]. Note that other arrays like [ 2, 6, 3, 9, 7 ], [ 2, 3, 6, 9, 7 ] also represent min-heap.
#include <bits/stdc++.h> 
void heapify (vector<int> &arr, int index, int size){
    //To heapify an element, we first check if it is smaller than its children (since min heap)
    //So basically out of the left child right child and the parent, we find the smallest element
    //and then make that the parent. 
    int smallest = index; //considering the current parent as the smallest. 
    int left = 2*index+1; 
    int right = 2*index + 2; 
    if (left<size && arr[left] < arr[smallest])
        smallest = left; 
    if (right<size && arr[right] < arr[smallest])
        smallest = right; 
    swap (arr[index],arr[smallest]); 
    //Now if a swap hasnt taken place, we know that the current node is at its correct place
    //because all the nodes beneath it have already been processed as we have come from n/2 to 0. 
    //But if a swap has taken place, we need to check the swapped index again, cuz it might go down further
    if (smallest != index)//swap taken place{
        heapify (arr, smallest, size); //the index smallest has the value which was at index, so we need to check if it is at its correct place.
    }

vector<int> buildMinHeap(vector<int> &arr)
{
    //The heapify function works very simply. 
    //First we need to realise that all leaf nodes are already heapified. 
    //So they need not be checked. 
    //Also the indexes of leaf nodes are from (n/2 - n)th indexes. 
    //So we just need a for loop, which runs for indexes 0 - n/2. 
    //We decide to do this from right to left (n/2->0) as then we will start from the smallest
    //subtrees first. 
    //For every element, we call the heapify function.  
    for (int i = arr.size()/2; i>=0; i--){
        heapify (arr, i, arr.size()); 
    }
    return arr; 
}


/*
    TIME COMPLEXITY:
    
    Although heapify() can take O(log n) for a single node,
    buildMinHeap() is NOT O(n log n).

    Most nodes are near the bottom of the heap and require
    very little work:
    
        n/2 nodes  -> O(1) work
        n/4 nodes  -> O(1) to O(2) work
        n/8 nodes  -> O(1) to O(3) work
        ...
        1 node     -> O(log n) work

    Therefore, the total work is:

        O(n/2 * 1) + O(n/4 * 2) + O(n/8 * 3) + ...
        
    This series sums to O(n).

    Hence:
        TIME COMPLEXITY = O(n)


    SPACE COMPLEXITY:

    heapify() is recursive.

    In the worst case, recursion can go from the root
    all the way down to a leaf.

    Height of a binary heap = O(log n)

    Therefore:
        SPACE COMPLEXITY = O(log n)

    This is auxiliary space used by the recursion stack.
    The heap itself is built in-place, so no extra array is used.
*/



