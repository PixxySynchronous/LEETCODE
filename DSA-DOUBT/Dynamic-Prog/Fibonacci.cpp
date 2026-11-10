class Solution {
public:
    int fibb (int n , vector<int> & arr){
        if (n==0||n==1)
            return n; 
        //usually we do retrun fibb (n-1) + fibb (n-2) here. 
        //but it is possible that the fibb value for this n has already been calculated in some other recursion call so we first check that. If it has been calculated already we return that 
        if (arr[n] != -1)
            return arr[n]; 
        // If it hasnt been calculated we first calc and store its value in arr and then return
        arr[n] = fibb(n-1,arr) + fibb(n-2,arr); 
        return arr[n];
    }
    int fib(int n) {
        // when we call fib (4) it calls fib 3 and once that is calculated fully it calls fib 2. The problem is that fib 2 was already calculated for fib 3 but is being recalculated, causing wasted memory. so we use an array to store previous fib values. 
        // Since there is only one vairable in play here, n, so we use a 1d array.  
        vector<int> arr (n+1, -1); 
        return (fibb(n,arr)); 

    }
};
// since we need to calculate the fib value for all n atleast once, and then we reuse the values if needed again
// the time complexity is O(n) and the space complexity is also O(n) since we are using an array of size n+1 to store the fib values, and the recursion stack can go as deep as n in the worst case. 