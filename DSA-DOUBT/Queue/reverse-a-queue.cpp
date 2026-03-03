class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // // Approach 1: Use stack. 
        // stack <int> s; 
        // while (!q.empty()){
        //     s.push(q.front());
        //     q.pop(); 
        // }
        // while (!s.empty()){
        //     q.push(s.top()); 
        //     s.pop(); 
        // }
        // Approach 2 -> recursion -> take first element out, reverse remaining 
        //queue recursively and then enter the elemnt 
        if (q.empty())
        return;
        int first = q.front(); 
        q.pop(); 
        reverseQueue(q); 
        q.push(first);
    }
};
//both approaches have tc and sc o(n). For recursive calls, sc increases due to
//the depth of the recursive calls.