// Min Cost to Connect Ropes
// Solved
// Difficulty: MediumAccuracy: 42.73%Submissions: 290K+Points: 4
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. Return the minimum possible cost.

// Examples:

// Input: arr[] = [4, 3, 2, 6]
// Output: 29
// Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, giving a total minimum cost of 29. Any other order, such as connecting 4 and 6 first, results in a higher total cost of 38.
// Input: arr[] = [4, 2, 7, 6, 9]
// Output: 62 
// Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12. Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
// Input: arr[] = [10]
// Output: 0
// Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
class Solution {
  public:
    int minCost(vector<int>& arr) {
        //To get the minimum costs, we need to take the smallest two numbers. 
        //We need to pop those numbers from the array and then insert the sum of those 
        //2 numbers into the array. We also need to store the sum somewhere else to get the 
        //final ans which is the sum of all these sums.  
        //We need to repeat the popping and inserting till array size == 1. At which 
        //point the ans is equal to sum of all sums plus the remaining element. 
        //We can do this by using a min Heap. 
        //A priority queue of min Heap will always have the top as the smallest number
        //and the next top as the next smallest number. Pop both and then insert the sum. 
        if (arr.size()==1)
            return 0; 
        int ans = 0 ; 
        priority_queue<int, vector<int>, greater<int>> pq; 
        //Step 1: put all elements in the minheap priority queue .
        for (int x : arr)
            pq.push(x); 
        //Step 2: Till size isnt equal to 1 , repeat the additions. 
        while (pq.size()>1){
            int a = pq.top(); 
            pq.pop(); 
            int b = pq.top(); 
            pq.pop(); 
            int sum = a+b; 
            ans += sum; 
            pq.push(sum); 
        }
     
        return ans; 
        // We dont need to add the last element alag se because it was already taken into account in the 
        //loop before we inseerted it. 
        
    }
};