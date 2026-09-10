
// You are given an integer n.

// Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

// In standard formatting:

// A comma is inserted after every three digits from the right.
// Numbers with fewer than 4 digits contain no commas.
 

// Example 1:

// Input: n = 1002

// Output: 3

// Explanation:

// The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

// Example 2:

// Input: n = 998

// Output: 0

// Explanation:

// ​​​​​​​All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

 

// Constraints:

// 1 <= n <= 1015
class Solution {
public:
    long long countCommas(long long n) {
        // if (n<=999)
        //     return 0; 
        // long long count = 0; 
        // for (int i = 1000; i<=n ;i++){
        //     int x = i; 
        //     do{
        //         count++; 
        //         x=x/1000; 
        //     }
        //     while (x>=1000); 
        // }   
        // return count; 
        // 
        if (n<=999)
            return 0; 
        long long power = 1000; 
        long long count = 0; 
        //Look we have ranges of 10 to the pwer 3 or 1000. Every multiplication of 1000, we get a new comma. 
        // For a number n (lets say 10,000,000) we know that the first 999 numbers have no comma but the remaing 10,000,000 - 999 = whatever have atleast 1 comma. So we count all those commas. and then we go into the range 10 to the pwer 6. If n is still bigger than the range then n-10 to the power 6 numbers have another comma unaccounted for, so we count them and then increase the range to 10 to the power 9. if n is still bigger then the power then we do the same to count the number of thirs commas which we missed in the past passes. That is what is done in this loop. 
        while (power<=n){
            count += (n-power+1);
            power *= 1000;
        }
        return count; 
    }
};
