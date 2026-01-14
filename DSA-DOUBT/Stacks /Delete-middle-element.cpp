// Problem statement
// You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.

// A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.

// Example :-
// INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
// OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]

// The above example contains an odd number of elements, hence the middle element is clearly the (N+1) / 2th element, which is removed from the stack in the output.

// INPUT : ARR [ ] = [ 5, 6, 7, 8 ] , N = 3
// OUTPUT: ARR [ ] = [ 5, 7, 8 ]

// The above example contains an even number of elements, so out of the two middle elements, we consider the one which occurs first. Hence, the middle element would be ((N+1) / 2 - 1) element, which is 6 and is removed from the stack in the output.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 100    
// 1 <= N+1 <= 3000
// 0 <= data <= 10^9

// Where ‘T’ is the number of test cases, ‘N+1’ is the number of elements in the input Stack. ‘data’ is the value of each element in the stack.
 #include <bits/stdc++.h> 
void solve (stack<int>&inputStack, int mid , int count){
   if (count == mid ){
      inputStack.pop(); 
      return; 
   }
   int num = inputStack.top();
   inputStack.pop(); 
   count ++; 
   solve (inputStack, mid,count); 
   inputStack.push(num); 

}
void deleteMiddle(stack<int>&inputStack, int N){
	   int size = N; 
      int mid = size /2; 
     
      int count = 0; 
      solve (inputStack,mid,count); 
      
} 

//Recursive call returns when count reaches mid, popping the middle element. Then, as the recursion unwinds, 
//the other elements are pushed back onto the stack in their original order, 
//minus the middle element.
//Issue i faced was to define mid as N/2 instead of (N+1)/2.
//This is because stack is 0 indexed internally. So for both even and odd cases,
//N/2 gives the correct middle index to be removed. for  even and odd cases respectively.