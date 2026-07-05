// 56. Merge Intervals
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// Example 3:

// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort (intervals.begin(), intervals.end(), [](vector<int> a, vector<int>b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans; 
        //bool merge = false; 
       
        //My approach was to compare the second element to the frst element of the next cell,but cases like example 3 would break them, and hence sorting is required. 
        //NOTE: Sorting a 2D vector is o(nlogn)
        // for (int i = 0; i< intervals.size(); i++){
        //     if (merge==true){
        //         merge=false;
        //         continue; 
        //     }
        //     vector<int> set; 
        //     if (i==intervals.size()-1){
        //         set.push_back(intervals[i][0]);
        //         set.push_back(intervals[i][1]);
        //         ans.push_back(set); 
        //         continue;   
        //     }
        //     if (intervals[i][1] >= intervals[i+1][0]){
        //         set.push_back(intervals[i][0]);
        //         set.push_back(max(intervals[i+1][1], intervals[i][1]));
        //         ans.push_back(set);
        //         merge = true;
        //     }
        //     else{
        //         set.push_back(intervals[i][0]);
        //         set.push_back(intervals[i][1]);
        //         ans.push_back(set);          
        //           }
        // }
        // return ans;
        //Above approach doesn't take in account continuous merges, Just one merge. 
        //so input [[1,4],[0,2],[3,5]] gives output [[0,4],[3,5]] and not [0,5]
        vector<int> current = intervals[0]; //current equals the first row of intervals
        for (int i = 1; i< intervals.size(); i++){
        if(current[1] >= intervals [i][0]){    //if there is an overlap, update current value.
        //and then loop continues, since if statements were executed, else wont, so we move on to next pair 
        //in intervals 
            current [1] = max(current[1], intervals[i][1]); //we update the second value as starting time remains the same. 
        }
        else{ //if no overlap present, push current and then make the current element as current. 
            ans.push_back(current);
            current=intervals[i];
        }
        }
        ans.push_back(current); //push in last element. 
        return ans; 
    }
};