// You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

// We can only use the following functions on this stack S.

// is_empty(S) : Tests whether stack is empty or not.
// push(S) : Adds a new element to the stack.
// pop(S) : Removes top element from the stack.
// top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
// Note :
// 1) Use of any loop constructs like while, for..etc is not allowed. 
// 2) The stack may contain duplicate integers.
// 3) The stack may contain any integer i.e it may either be negative, positive or zero.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= 'T' <= 100
// 1 <=  'N' <= 100
// 1 <= |'V'| <= 10^9

// Where |V| denotes the absolute value of any stack element.

// Time limit: 1 sec
// Sample Input 1:
// 1
// 5
// 5 -2 9 -7 3
// Sample Output 1:
// 9 5 3 -2 -7
// Explanation of Sample Input 1:
// 9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last. 
// Sample Input 2:
// 1
// 5
// -3 14 18 -5 30
// Sample Output 2:
// 30 18 14 -3 -5
// Explanation of Sample Input 2:
// 30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last. 




#include <bits/stdc++.h> 
void insertAtCorrectPlace (stack<int>& stack, int x ){ 
	if(stack.empty() || x >= stack.top()){
		stack.push(x); 
		return; 
	}
	int temp = stack.top(); 
	stack.pop(); 
	insertAtCorrectPlace(stack ,x); 
	stack.push(temp); 
}
void sortStack(stack<int> &stack)
{
	if (stack.empty())
	return; 
	int x = stack.top();
	stack.pop(); 
	sortStack(stack); 
	insertAtCorrectPlace(stack, x); 

}

//Simple: take top element. Sort the rest of the list via recursion
//and then insert the top element at the right position. 
//to inssert at right position -> comparre with top elemnt, 
//if its smaller then keep on comparing recursively. 