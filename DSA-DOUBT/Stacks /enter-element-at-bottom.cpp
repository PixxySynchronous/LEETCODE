// You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

// Note :
// If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.

#include <bits/stdc++.h> 
void solve (stack<int>& myStack, int size, int x){
    if (myStack.empty()){
        myStack.push(x);
        return; 
    }

    int num = myStack.top();
    myStack.pop();
    
    solve (myStack, size, x);
    myStack.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{   int size = myStack.size(); 
    int count =0 ; 
    solve (myStack,size,x); 
    return myStack; 
}
//Used the same approach as deleting middle element from stack.
//Recursive function pops all elements until stack is empty, then pushes x,
//then as recursion unwinds, pushes back all other elements in original order.
//This effectively places x at the bottom of the stack.
//Did use the counter variable first to keep track but found it unnecessary and removed it as we can use the empty() check directly.