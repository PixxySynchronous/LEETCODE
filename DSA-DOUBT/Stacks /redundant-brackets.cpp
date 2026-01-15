// Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

// Note :
// A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

// For Example :
// ((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
// While (a + (b*c)) does not have any pair of redundant brackets. 

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> stack; 
  
    for (char c: s){
        if (c == ')'){
            bool hasoperator = false; 
            while (stack.top() != '('){
                if (stack.top()=='+' ||stack.top()=='-' ||stack.top()=='*' ||
                stack.top()=='/'){
                    hasoperator= true; 
                }
                stack.pop(); 
            }
            if (hasoperator == false){
                return true; 
            }
            else {
            stack.pop(); // pop out the remaining ) in the stack  
            continue; }
        }
        stack.push(c); 
    }
    return false; 
}
// Time Complexity: O(n)
// Space Complexity: O(n)   
// Redundant brackets can be identified by checking if there are any operators between a pair of parentheses. 
//If there are no operators, the brackets are redundant.