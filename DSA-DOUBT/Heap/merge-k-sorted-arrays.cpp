//  Merge K Sorted Arrays
// Moderate
// 80/80
// Average time to solve is 15m
// 250 upvotes
// Asked in companies
// Problem statement
// You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 5
// 1 <= K <= 5
// 1 <= N <= 20
// -10^5 <= DATA <= 10^5

// Time Limit: 1 sec 
// Sample Input 1:
// 1
// 2
// 3 
// 3 5 9 
// 4 
// 1 2 3 8   
// Sample Output 1:
// 1 2 3 3 5 8 9 
// Explanation of Sample Input 1:
// After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].
// Sample Input 2:
// 1
// 4
// 3
// 1 5 9
// 2
// 45 90
// 5
// 2 6 78 100 234
// 1
// 0
// Sample Output 2:
// 0 1 2 5 6 9 45 78 90 100 234
// Explanation of Sample Input 2 :
// After merging the given arrays/lists [1, 5, 9], [45, 90], [2, 6, 78, 100, 234] and [0], the output sorted array will be [0, 1, 2, 5, 6, 9, 45, 78, 90, 100, 234].
#include <bits/stdc++.h> 
class Node { //we need this to make sure we increment in the array jiska element pop hua hai. 
//Since we have a 2d array, where rows have individual arrays and cols have elements. 
    public:
        int data;
        int row; 
        int col; 
        Node (int data, int row, int col){
            this -> data = data; 
            this -> row = row; //tells which array
            this -> col = col; //tells which element of an array. 
        }
}; 
struct compare {
    bool operator()(Node a, Node b) {
        return a.data > b.data; //a gets lower priority than b if val of a is greater. 
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    //We have k sorted arrays. We need one fully sorted array. 
    //One approach is to put all elements into an array and sort it. 
    //If total elemnts = N = k*n then tc will be O(NlogN). 
    //In the above approach we dont make use of the fact that each individual array is sorted in itself. 
    //If we use min heap we need to put in N elements in a min heap of size k and each insert
    //is log k so tc becomes o(Nlogk). 

    
    vector<int> ans;
    priority_queue<Node, vector<Node>, compare> pq; 
    //Step 1: There are k arrays. We need to first insert the first elements of all these arrays. 
    for (int i = 0 ; i<k ; i++){
        Node temp (arr[i][0],i,0); 
        pq.push(temp); 
    }
    //Now we pop the smallest element and put it in the ans, and then we push the 
    //next element in of that array (jiska element pop hua hai) in the minheap. We keep doing this till all elements 
    //have been processed i.e the heap is empty. 
    while (!pq.empty()){
        Node temp = pq.top(); 
        pq.pop(); 
        ans.push_back (temp.data); 

        //Now we need to access the next element of the rowth array.
        if (temp.col + 1 < arr[temp.row].size()) //that element should exist.
            {   Node temp2 (arr[temp.row][temp.col + 1], temp.row, temp.col+1); 
                pq.push (temp2); 
            }
    }
    return ans; 
}
