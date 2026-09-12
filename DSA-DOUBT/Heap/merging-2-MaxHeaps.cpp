#include <bits/stdc++.h> 

void heapify (vector<int>& ans, int index){
    if (index >= ans.size())
        return; 
    int largest = index;
    int leftIndex = 2*index + 1; 
    int rightIndex = 2*index + 2; 
    if (leftIndex <ans.size() && ans[largest] < ans[leftIndex])
        largest=leftIndex; 
    if (rightIndex < ans.size() && ans[largest] < ans[rightIndex])
        largest = rightIndex; 
    if (largest != index){
        swap (ans[largest], ans[index]);
        heapify (ans, largest); 
    }
}
void buildHeap (vector<int>& ans){
    int n = ans.size(); 
    for (int i = n/2 -1; i>=0 ; i--){
        heapify (ans,i);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    //approach is simple. Merge the given 2 arrays and then buil heap from the combined vector.
    vector<int> ans; 
    for (int i = 0; i<n ;i++){
        ans.push_back(arr1[i]); 
    }
    for (int i = 0; i<m ;i++){
        ans.push_back(arr2[i]); 
    }
    buildHeap (ans); 
    return ans; 
}

//TC is just o(n+m) as we are just merging the 2 arrays and then building heap from the combined array.