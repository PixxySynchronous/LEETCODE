// Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.

// For Example:
// “{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
// Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.

// Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.

// For Example:
// Minimum operations to make ‘STR’ =  “{{“ valid is 1.
// In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid string.

// Note:
// Return -1 if it is impossible to make ‘STR’ valid.

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  int operations = 0 ;
  stack<char> st;  
  for (char c : str){
    if (c == '}' ){
        if (st.empty()){
        st.push('{');
        operations++;
        } //cant put closing brackets in empty stack so flip it. 
        else{
          st.pop(); 
        }//pop an opening bracket for a closed bracket. 
    }
    else{
      st.push(c); //push only opening brackets 
    }
  }

  if (st.size()%2 != 0){
    return -1; //cant fix odd number of open brackets by flipping
  }
  else {
    operations+=(st.size()/2); 
    return operations; 
  }

  
}
//Could do everything on my own. 