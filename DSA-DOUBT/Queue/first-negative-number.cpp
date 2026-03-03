// Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

// Note: If a window does not contain a negative integer, then return 0 for that window.

// Examples:

// Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
// Output: [-8, 0, -6, -6]
// Explanation:
// Window [-8, 2] First negative integer is -8.
// Window [2, 3] No negative integers, output is 0.
// Window [3, -6] First negative integer is -6.
// Window [-6, 10] First negative integer is -6.

class Solution {
  public:
  //Approach 1: brute force of o(n2). Problem is we are rechecking several elements again and again
  // so we need to store those elements. Using stack will give me lifo meaning the last
  //element will be returned not the first, hence we need fifo, hence we use a queue. 
    // int checkWindow (vector<int>& arr, int start, int end){
       
    //     for (int i = start; i<= end; i++){
    //         if (arr[i]<0){
    //             return arr[i]; 
    //         }
    //     }

    //     return 0;
    // }
    vector<int> firstNegInt(vector<int>& arr, int k) {
    //     vector <int> output; 
    //     int start = 0 ; 
    //     int end = start + k - 1 ; 
    //     while (end < arr.size()){
    //         output.push_back(checkWindow(arr,start,end));
    //         start++;
    //         end++; 
            
    //     }
    // return output;
    
    //Approach 2: make a queue. Store only the indices of negative numbers. 
    //Check if the index of the negative number falls in the window.
    queue <int> q; 
    vector<int> output; 
    for (int i = 0 ; i < arr.size() ; i ++){
        if ( arr[i] < 0)
            q.push(i); 
        if (!q.empty() && q.front()<i-k+1)//CHECK IF THE NEGATIVE NUMBER FALLS IN THE WINDOW 
            q.pop(); 
        if (i>=k-1){//need to start sliding window once the first window is in fully. If its not in, redo the loop
            if (!q.empty())
                output.push_back(arr[q.front()]); //dont pop after this as the popping happens above already. 
            else 
            output.push_back(0);
            
        }
        
    }
    return output; 
    }
};