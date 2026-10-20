// 3551. Minimum Swaps to Sort by Digit Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

// Return the minimum number of swaps required to rearrange nums into this sorted order.

// A swap is defined as exchanging the values at two distinct positions in the array.

 

// Example 1:

// Input: nums = [37,100]

// Output: 1

// Explanation:

// Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
// Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
// Thus, the minimum number of swaps required to rearrange nums is 1.
// Example 2:

// Input: nums = [22,14,33,7]

// Output: 0

// Explanation:

// Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
// Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
// Thus, the minimum number of swaps required to rearrange nums is 0.
// Example 3:

// Input: nums = [18,43,34,16]

// Output: 2

// Explanation:

// Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
// Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
// Thus, the minimum number of swaps required to rearrange nums is 2.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// nums consists of distinct positive integers.
class Solution {
public:
    int sumOfNum (int num){
        int ans = 0; 
        while (num > 0){
            ans += num%10;
            num = num/10; 
        }
        return ans; 
    }
    void arrange (vector<pair<int,int>>& nums){
        sort (nums.begin(), nums.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
            int suma = sumOfNum (a.first);
            int sumb = sumOfNum (b.first); 
            if (suma == sumb)
                return a.first<b.first; 
            return suma<sumb; 
        });
    }
    int minSwaps(vector<int>& nums) {
        // This is basically 2 qsns in one. One is the sroting through sum of digits, and second is the finding of min swaps. 
        // To sort the array through sum of digits, we needed to give the comparator the function. We are giving const int pair due to the second rpoblem, otherwise its syntax is easy.  

        // The min swap algorithm is a bit tricky to learn. 
        // What we need is: the number, its original index and its correct index all togethr. 
        vector<pair<int,int>> origMap; // we make this to store the original index 
        for (int i = 0 ; i<nums.size(); i++){
            origMap.push_back({nums[i],i}); //original index of all elements.. 
        }
        arrange(origMap); //now we sort this to make sure all the numbers are in their correct positions. So now we have index of number as its correct position and number.second as the original index. And ofcourse the number itself, so we got all 3. 
        vector <bool> visited (nums.size(),false); 
        int swaps = 0; 
        for (int i = 0 ; i<nums.size(); i++){ //Now we loop across each element to detect its cycle. 
        // basically a cycle of 3 looks like this: 
        // element originally at 1 wants to goto 0, element orignally at 0 wants to go to 2 and element originally at 2 wants to go at 1 (we reached where we started) 
        // A cycle of size k will require k-1 swaps. 
        // all elements in the cycle have the same cycle so there is no need to process them again so we make a visited array to account for that. 
            if (visited[i] || origMap[i].second == i){
            //origMaps[i] will have the numb in its correct index. origMap[i].second shows its original positiion in nums. if they are equal, we can skip. 
            //either we have laready visited the element, or the element is in its correct index, we skip
                continue; 
            }
            int j = i ; 
            int cycleSize = 0 ; 
            while (visited[j]!=true){
                visited[j] = true; 
                j = origMap[j].second; 
                cycleSize++; 
            }
            swaps += cycleSize -1; 
            
        }
        return swaps; 

    }
};