// 9. Palindrome Number
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer x, return true if x is a palindrome, and false otherwise.

 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) //negative numbers cant be palindrome
            return false; 
        if (x<=9) //all single digits are palindrome. 
            return true; 
        if (x%10 == 0) //numbers ending with 0 cant be palindrome 
            return false; 
        long long rev = 0; 
        int temp = x; 
        while (x!=0){
            int dig = x%10; 
            rev = rev*10 + dig; 
            x=x/10; 
        }
        if (temp==rev)
            return true; 
        else
            return false; 
    }
};
//If the number is so big that even long long causes an issue, what we can do is try to reverse 
//only half the digits. 
//eg) 1221 -> 122 -> 12 when /10 and simltaneously the rev becomes 1->12
// so a condition while (x>revhalf) and then same thing in the loop as above works. 
// then check if x == rev half then return true. 
// for odd length numbers we go one step beyond for reverse i.e 
// eg) 121 -> 12 -> 1 and rev goes from 0 -> 1 -> 12 (we go from 1 -> 12 as x is 12 at that point and still bigger than 1) so for odd numbers we check x == remaininghalf/10. 
// Just check both and return with OR. 
