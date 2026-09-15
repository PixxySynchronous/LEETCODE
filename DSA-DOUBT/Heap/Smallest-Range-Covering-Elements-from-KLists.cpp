// 632. Smallest Range Covering Elements from K Lists
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]

class Solution {
public:
    class element {
        public:
            int row; 
            int col; 
            int data; 
            element (int data, int row, int col){
                this -> row = row; 
                this -> col = col; 
                this -> data = data; 
            }
    }; 
    class compare {
        public:
            bool operator()(element a, element b){
                return a.data>b.data; 
            }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Approach 1: Calculate all possible ranges. 
        // eg for test case 1 all ranges would be 4-10,4-15,4-24,4-26,4-0 etc...
        // Then calculate differences and pick the smallest one. There are n*k elements and 
        // for each element n*k -1 range can be made so tc os o(n2k2). 
        // Approach 2: We first point k pointers each to the start of the list. We calculate the range as maxElem - minElem. this range gaurantees the condition of atleast one number from each list getting in the range as the other elements at the other pointers will be > than the least element and < max element. Now, to decrease the differnce between the range, we can either increase the min element or decrease the max element. We cant decrease the max element as we are starting from the start of an ascending list so we just increment the pointer with the min element. For that we need to know which array (row) it belongs to so we need to make a class. Finding of min and max elements amongst k elements can take o (k) tc. But we can use minHeap to get min element in o(logK) and track max element while inserting the element in the heap. We stop searching for pairs as soon as one of the lists end. 

        //Step 1: Insert the first elements of all the k lists in the minHeap. 
        priority_queue<element, vector<element>, compare> pq; 
        int maxi = INT_MIN; //need to keep track of max element while inserting. 
        int k = nums.size(); //number of rows/lists. 
        for (int i = 0 ; i<k ; i++){
            maxi = max (maxi, nums[i][0]); 
            element elem (nums[i][0], i, 0); 
            pq.push(elem); 
        }
        vector<int> ans;
        int range = INT_MAX;  
        while (!pq.empty()){
            element min = pq.top(); 
            pq.pop(); 
            //Step 2: find a better range. If found, update ans and range.
            if (maxi-min.data < range){ // found a better range. 
                ans.clear(); 
                ans.push_back(min.data);
                ans.push_back(maxi); 
                range = maxi-min.data; 
            }
            //Now need to push in the next element in the array which had the current min elemnt
            //But first we need to check if there is a next element at all or no. 
            if (min.col + 1 < nums[min.row].size()){
                element next (nums[min.row][min.col + 1], min.row, min.col+1);
                pq.push(next); 
                maxi = max (maxi,next.data); 
            }
            else{
                break; //if the next element doesnt exist, a list has been exhausted, we have found the ans. 
            }
        }
        return ans;
    }
};