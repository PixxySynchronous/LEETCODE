// Problem statement
// Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.



// Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.



// Example:
// Input: [1,2,3,4,5] 
// Output: [5,4,3,2,1]

void insertAtBottom (stack<int>& stack, int x){
    if (stack.empty()){
        stack.push(x);
        return; 
    }
    int temp = stack.top();
    stack.pop(); 
    insertAtBottom(stack,x);
    stack.push(temp); 
}

void reverseStack(stack<int> &stack) {
    if (stack.empty())
    return; 
    int temp = stack.top(); 
    stack.pop(); 
    reverseStack(stack); 
    insertAtBottom(stack,temp); 

}

//Couldnt come up with this approach myself.
//Approach: Recursively pop all elements until stack is empty. Then, as recursion unwinds, insert each popped element at the bottom of the stack.
//This effectively reverses the stack.
//tc is o(n2) as for each of the n elements, we may have to do up to n insertions at bottom.
//sc is o(n) due to recursion stack.