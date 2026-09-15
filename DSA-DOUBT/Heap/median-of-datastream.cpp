#include <queue>
#include <vector>
using namespace std;
int findMedian (int element, priority_queue<int,vector<int>, greater<int>>& minHeap, priority_queue<int> &maxHeap){
	// for an array: maxheap, median, minheap. We need to consider the sizes of min and max heaps. 
	/* if both are of size n (or equal), then it means the median is the average of the two tops of the heaps. 
	If minHeap = n-1 and maxHeap = n it means median is maxheap top. If minHeap = n and maxHeap = n-1, median element
	is minheaptop. So first we need to check the sizes of the heap, then consider what happens to them once another element
	is added to the array and then return median acc. 
	*/
	/* INVARIANT: everything in maxHeap (left) must be <= everything in minHeap (right).
	Since each heap keeps its extreme at the top, it is enough that maxHeap.top() <= minHeap.top().
	*/
	// First element
    if (maxHeap.empty()) {
        maxHeap.push(element);
        return element;
    }
	if (minHeap.size() == maxHeap.size()){//then after inserting the new element either min will be bigger or max heap will be bigger. 
		/* Equal sizes: nothing moves between heaps, the element goes straight to one side.
		So comparing with either top is fine here.
		*/
		if (element <= maxHeap.top()){//it goes in maxHeap,(the smaller numbers grp) making maxHeap n+1 and minheap size n so median is maxheap top. 
			maxHeap.push(element); 
			return maxHeap.top(); 
		}
		else{ //element is greater than all maxHeaps so it goes in minHeap grp. 
			minHeap.push(element);
			return minHeap.top(); 
		}
	}
	/* RULE FOR THE TWO UNEQUAL BRANCHES BELOW:
	Always compare the element against the top of the heap you might MOVE an element from.
	A move creates one new pair that must be in order: the moved top and the new element.
	Comparing against the other heap's top says nothing about that pair, and the invariant can break.
	Example of the old bug (comparing with maxHeap.top() here): maxHeap={5}, minHeap={20,30}, insert 10.
	10 > 5, so 20 moved left and 10 went right, giving maxHeap.top()=20 > minHeap.top()=10. Broken.
	The two branches must be MIRROR images, not copies of each other.
	*/
	else if (minHeap.size() > maxHeap.size()){
		// minHeap is bigger, so we may move minHeap.top(). Compare with minHeap.top().
		if (element <= minHeap.top()){ //element goes into the smaller numbers grp, making min heap and max heap equal
			// Safe: element <= minHeap.top() <= everything on the right, so element belongs on the left.
			maxHeap.push(element); 
			//since now both heaps have equal sizes, we return the avg of their tops.
			return ((minHeap.top()+maxHeap.top())/2); 
		}
		else { //element should go into minHeap. But then difference between minHeap and maxHeap increase to 2. We want it to be less than equal to 1. 
		//So to make sure this disaprity doesnt happen, we send the minheap top to maxheap, before inserting element into minHeap. 
			// Safe: the moved top r is >= everything on the left, so it becomes the new left top.
			// element > r, so element correctly stays on the right.
			int switchSides = minHeap.top(); 
			minHeap.pop(); 
			maxHeap.push(switchSides); 
			//Now sizes are minHeap: went from n -> n-1. maxHeap went from: n-1 -> n
			//now insert element into minHeap 
			minHeap.push(element); 
			//since now sizes are equal, return avg. 
			return ((minHeap.top()+maxHeap.top())/2); 

		}

	}
	else { //maxHeap has n elements, minHeap has n-1 elements. 
		// maxHeap is bigger, so we may move maxHeap.top(). Compare with maxHeap.top() (mirror of the branch above).
		if (element <= maxHeap.top()){
			//we need to add element in maxheap but that makes the difference go to 2, so we first shift one element. 
			// Safe: the moved top l is <= everything on the right, so it becomes the new right top.
			// element <= l, so element correctly stays on the left.
			int switchSides = maxHeap.top(); 
			maxHeap.pop(); 
			minHeap.push(switchSides); 
			maxHeap.push(element); 
			//since now sizes are equal, return avg. 
			return ((minHeap.top()+maxHeap.top())/2); 
		}
		else{
			// Safe: element > maxHeap.top() >= everything on the left, so element belongs on the right.
			minHeap.push(element);
			//since now sizes are equal, return avg. 
			return ((minHeap.top()+maxHeap.top())/2); 
		}

	} 

}




vector<int> findMedian(vector<int> &arr, int n){
	
	/* I need to find median of a data stream, i.e elements keep on getting added 
	If it was a normal sorted array, id just return the avg of the 2 middle values or the 
	middle value itself if the size was odd. But since the array isnt sorted, we would need to sort 
	it first and then return the median, and then whenever a new element came from the stream, we would need
	to sort the entire array again and then return the medium. 
	if we use the sort function which uses tc 0(nlogn), and we sort for all elements coming in which is n, 
	tc becomes o(n*nlogn). If we use insertion sort, which considers the array to be already sorted, and then
	just insert the new element at its correct position, it will take tc o(logn) to find the position of the new element
	and o(n) to insert it (as array insertion would require shifting), so overall insertion would be o(n) done for n
	elements giving tc o(nsq). 
	What we can think is, we dont need the entire array to be sorted, we just need the median, element to its left and element to its right
	be in the correct order.  
	To implement this we can consider the array as:
	[maxHeap, minHeap]. maxHeap top will be < median. minHeap top > median. 
	When new element comes we need to check a few conditions. These conditions are written in the function.
	*/
	priority_queue<int,vector<int>, greater<int>> minHeap; 
	priority_queue<int> maxHeap; 
	vector<int> ans; 
	for (int i = 0 ; i<arr.size(); i++){
		//this for loop dictates the stream of data being added. 
		int median = findMedian (arr[i], minHeap, maxHeap); 
		ans.push_back (median); 
	}
	return ans; 
}