//Leetcode 191 Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
class Solution {
public:
    int hammingWeight(int n) {
        int counter=0;
        while (n!=0){
            int bit = n&1;
            if (bit ==1){
                counter++;
            }
            n=n>>1;

        }
        return counter;
        
    }
};