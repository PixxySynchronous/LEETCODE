#include <bits/stdc++.h> 
//This is so simple on god. First heapify the entire array. 
//Now to sort the array, follow these 2 steps:
	//1. Swap the root and the last index.
	//2. Decrese the size of the array. 
	//3. Heapify the remaining array. 
	//4. repeat till size == 1
void heapify (vector<int> &arr, int size, int index){ //tc:o(logn)
	//if we use maxheap, we put the largest element at the end, making the array ascending.  
	int largest = index; 
	int left = 2*index + 1; 
	int right = 2*index + 2;
	if (left < size && arr[left]>arr[largest])
		largest = left; 
	if (right < size && arr[right]>arr[largest])
		largest = right; 
	if (largest != index){
		swap (arr[index], arr[largest]); 
		heapify (arr,size,largest); 
	}
}
void buildHeap (vector<int> &arr, int size){ //tc(on)
	for (int i = arr.size()/2; i>=0; i--){
		heapify(arr,arr.size(),i); 
	}
}

vector<int> heapSort(vector<int>& arr, int n) {
	//Step 1: make the initial array a heap. 
	buildHeap(arr,n) ;
	//Step 2: Repeat till size==1
	int size = n ;
	while (size >=1){
		//swap root and last value of the viable array. 
		swap (arr[0], arr[size-1]);
		//decrease size. 
		size --; //Indexes beyond this are already sorted. 
		//The remaining array is a heap, except the new element which is at the 
		//first index, so just heapify that. 
		heapify (arr,size,0);
	}
	return arr; 
}
//sine heapsort runs heapify n times, the time complexity is O(nlogn).
//SC is o(logn) for the recursion stack of heapify.