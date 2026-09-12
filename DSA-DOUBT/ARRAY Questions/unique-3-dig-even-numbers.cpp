// 3483. Unique 3-Digit Even Numbers
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

// Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

 

// Example 1:

// Input: digits = [1,2,3,4]

// Output: 12

// Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.

// Example 2:

// Input: digits = [0,2,2]

// Output: 2

// Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.

// Example 3:

// Input: digits = [6,6,6]

// Output: 1

// Explanation: Only 666 can be formed.

// Example 4:

// Input: digits = [1,3,5]

// Output: 0

// Explanation: No even 3-digit numbers can be formed.

 

// Constraints:

// 3 <= digits.length <= 10
// 0 <= digits[i] <= 9
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st; 
        int count = 0; 
        for (int i = 0 ; i<digits.size(); i++){
            for (int j= 0; j<digits.size();j++){
                for (int k = 0; k<digits.size(); k++){
                    if (i!=j && i!=k && j!=k){
                        int digit = (digits[i] *100) + (digits[j] *10) + digits[k];
                        if (digit%2!=0 || digit<100) continue; 
                        if (st.find(digit) == st.end()){
                            count++;
                            st.insert(digit);
                        }

                    }
                }
            }
        }
        return count;
    }
    //Above approach is simple, a triple loop to find 3 digits and then making the number. 
    //Then checking if the number has been visited or not before. 
    //Another approach also follows a triple loop. We first make a frequency array of all the numbers. 
    //Then we run the first loop for the hundreths place (to indicate how many digits can be in it), for every iteration we do freq --. Then second loop for tenths place and thrid for ones place (which only requires even numbers). Once all loops are iterated once we increment it back
//     class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         int freq[10] = {};

//         for (int x : digits)
//             freq[x]++;

//         int ans = 0;

//         for (int a = 1; a <= 9; a++) {          // hundreds
//             if (freq[a] == 0) continue;

//             freq[a]--;

//             for (int b = 0; b <= 9; b++) {      // tens
//                 if (freq[b] == 0) continue;

//                 freq[b]--;

//                 for (int c = 0; c <= 8; c += 2) { // units
//                     if (freq[c] > 0)
//                         ans++;
//                 }

//                 freq[b]++;
//             }

//             freq[a]++;
//         }

//         return ans;
//     }
// };
};
//TC is o(1) since the maximum number of digits is 10, so the triple loop will run at most 10*10*10 times.