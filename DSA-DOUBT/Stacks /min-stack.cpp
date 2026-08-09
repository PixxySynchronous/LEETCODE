// Min Stack
// Medium
// Topics
// Company Tags
// Hints
// Design a stack class that supports the push, pop, top, and getMin operations.

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// Each function should run in 
// O
// (
// 1
// )
// O(1) time.

// Example 1:

// Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

// Output: [null,null,null,null,0,null,2,1]

// Explanation:
// MinStack minStack = new MinStack();
// minStack.push(1);
// minStack.push(2);
// minStack.push(0);
// minStack.getMin(); // return 0
// minStack.pop();
// minStack.top();    // return 2
// minStack.getMin(); // return 1
// Constraints:

// -2^31 <= val <= 2^31 - 1.
// pop, top and getMin will always be called on non-empty stacks.
class MinStack {
    stack<int> st; 
    stack<int> minSt; //Need to declare these here as I need to use them for all functions. 
public:
    MinStack() {}
    //Approach is to maintain 2 stacks. One is the normal stack and the other keeps the minimum element 
    // if the corresponding element would be on top of the main stack. Like a prefix. 
    
    void push(int val) {
        st.push(val); 
        if (minSt.size()==0){
            minSt.push(val);
            return; 
        }
        if (st.top()<minSt.top())
            minSt.push(val); //The current minElem gets outmogged by the newest elem getting pushed so we push that in minst as well. 
        else{
            int minelem = minSt.top();
            minSt.push(minelem);//repush the minelem as it is smaller than the current value being pushed in
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop(); //Need to pop both!
    }
    
    int top() {
        return st.top();

    }
    
    int getMin() {
       return minSt.top(); 
    }
};
