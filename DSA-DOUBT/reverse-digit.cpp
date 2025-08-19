//LEETOCDE 07 // Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

class Solution {
public:
    int reverse(int x) {
        // bool negative=false;
        // if (x<0){
        //     negative=true;
        //     x=x*-1;
        // }
        int reverse = 0;
        // int i=0;
        while (x != 0) {
            int digit = x % 10;
            if (reverse > INT_MAX / 10 ||
                (reverse == INT_MAX / 10 && digit > 7))
                return 0;
            if (reverse < INT_MIN / 10 ||
                (reverse == INT_MIN / 10 && digit < -8))
                return 0;
            reverse = (reverse * 10 + digit);
            x = x / 10;
        }
        // if(negative==true){
        // reverse=reverse*-1;

        return reverse;
    }
};

//Couldn't do the boundary conditions for the negative numbers, without usinng redundant code.Figured later that both positive and negative numbers can be handled in the same way.
//Need to learn the boundary conditions and their implementation in C++.