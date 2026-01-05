class Solution {

public:
    string removeDuplicates(string s) {
        stack <char> st; 
        for (char c : s){
            if (st.empty()){
                st.push(c);
                continue;
            }
            if (st.top()==c)
                st.pop(); 
            else
                st.push(c); 
        }
        string ans; 
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop(); 
        }
        reverse (ans.begin(), ans.end()); 
        return ans; 
    }
};

//This is a stack solution with tc O(n) and sc O(n).
//I thought of a simple function with .erase but that would have been O(n^2).