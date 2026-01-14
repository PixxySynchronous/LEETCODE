// Problem statement
// You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .



// Return true if the given string 'S' is balanced, else return false.



// For example:
// 'S' = "{}()".

// There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
// So the 'S' is Balanced.

bool isValidParenthesis(string s)
{
    stack<char> stack;
    stack.push('a');  
    for ( char c : s){
        if (stack.top() == '(' && c == ')'){
            stack.pop();
            continue; 
        }
        else if (stack.top() == '{' && c == '}'){
            stack.pop();
            continue; 
        }
        else if (stack.top() == '[' && c == ']'){
            stack.pop();
            continue; 
        }
        else  
        stack.push(c); 

    }
    if (stack.size() == 1)
    return true; 
    else 
    return false; 
}

// Approach: Use a stack to keep track of opening brackets. For each closing bracket, check if it matches the
// top of the stack. If it does, pop the stack; if not, return false. At the end, if the stack is empty, return true; otherwise, return false.
// Problems in my approach was i wa checking the top of the stack without ensuring the stack was not empty. this created runtime errors for test cases like "())".
// To fix this i pushed a dummy character at the bottom of the stack at the start.
//however im also putting in closing brackets into the stack which is unnecessary. but it works fine.
//traditionally only opening brackets are pushed onto the stack.

// bool isValidParenthesis(string s)
// {
//     stack<char> st;

//     for (char c : s) {
//         if (c == '(' || c == '{' || c == '[') {
//             st.push(c);
//         } else {
//             if (st.empty()) return false;

//             if ((st.top() == '(' && c == ')') ||
//                 (st.top() == '{' && c == '}') ||
//                 (st.top() == '[' && c == ']')) {
//                 st.pop();
//             } else {
//                 return false;
//             }
//         }
//     }
//     return st.empty();
// }
