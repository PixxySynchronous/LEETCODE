// Leetcode-231 Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

 


class Solution {
public:
    bool isPowerOfTwo(int n) {
         if (n==0){
                return false; 
            }
         if (n==1){
            return true;
         }
        while (n){
            if (n==1){
                return true; 
            }
            if(n%2!=0){
                return false;
            }
            n=n/2;
       
        }
        return true;
    }
};


// Optimized solution using bitwise operations:
//one liner 

// Bitwise Trick:

//         - A power of two has only ONE bit set in binary.
//             Examples:
//             2  => 00000010
//             4  => 00000100
//             8  => 00001000

//         - Subtracting 1 flips all bits after the set bit:
//             4     => 00000100
//             4 - 1 => 00000011

//         - So: n & (n - 1) == 0 only for powers of two.

//         🔒 Also make sure n > 0 to exclude 0 and negatives.
//         */

//         return n > 0 && (n & (n - 1)) == 0;
//     }
// };