// 
#include<stack>
#include <algorithm>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // initail brute force approach is o(n2).
    //i know i need to use stack as this is a "nearest element search"
    // type of qsn. 

    stack<int> st; 
    st.push(-1); //if no element is smaller then -1 shall be returned so it is at bottom
    vector <int> ans;  
    for (int i = arr.size()-1; i>=0 ; i--){
        if (st.top() >= arr[i]){ //starting from left side to decrease the search area. 
            while (st.top() >= arr[i])
            st.pop(); 
        }

        ans.push_back(st.top());
        st.push(arr[i]); 
        
    }
    
    reverse(ans.begin(), ans.end()); 
    return ans; 
}