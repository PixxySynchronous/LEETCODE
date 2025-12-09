// Leetcode 1281 Given an integer number n, return the difference between the product of its digits and the sum of its digits.

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int product=1;
        while(n!=0){
            int digit=n%10;
            sum=sum+digit;
            product=product*digit;
            n=n/10;
        }
        int result = product-sum;
        return result;
        
    }
};