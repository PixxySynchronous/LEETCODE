//Leetcode 1009//Given an integer n, return its complement.

//  class Solution {
// public:
//     int bitwiseComplement(int n) {
//         int compliment = 0;
//         int complimentdecimal=0;
//         int i =0;
//         if (n==0){
//             return 1;
//         }
//         while(n!=0){
//             int bit = n&1;
//             // cout<<bit<<endl;
//             int revbit=bit^1;
//             // cout<<revbit<<endl;
//             compliment=(revbit * pow(10,i)+ compliment);
//             i++;
//             n=n>>1;

//         }
//         i=0;
//         cout<<compliment<<endl;
//         while(compliment!=0){
//             int cbit=compliment%10;
//             cout<<"This is cbit "<<cbit<<endl;
//             if(cbit==1){
//                 complimentdecimal=(cbit*pow(2,i))+complimentdecimal;
//                 // cout<<complimentdecimal<<endl;
//             }
//             cout<<complimentdecimal<<endl;
//             i++;
//             compliment=compliment/10;
//         }
//         return complimentdecimal;
//     }
// };

//THIS WAS MY ORIGINAL CODE FOR THE SOLUTION BUT IT WAS NOT EFFICIENT ENOUGH. THIS IS BECASE I WAS CONVERTING THE BITS TO DECIMAL AND THEN BACK TO BITS. THIS IS NOT REQUIRED. WE CAN JUST DO THE BITWISE OPERATIONS DIRECTLY. SO INSTEAD OF USING POW(2,i) TO CREATE THE COMPLIMENT AS A DECIMAL, I HAVE TO USE BITWISE OPERATIONS ONLY.\
//GPT GAVE ME THE MASK LOGIC TO GET NUMBER OF BIT AND ALLOW ME TO JUST USE THE NOT OPERATION. 
class Solution {
public:
    int bitwiseComplement(int n) {
          if (n == 0) return 1;
        int temp=n;
        int mask=0;
        while(temp){
            mask=mask<<1|1;  //Mask =000 initially so we shift all 0s and then add a 1 making mask 001. in next iteration mask=001, we shift it to 010 then add a 1                              to make it 011 repeating this till temp exists gives us a mask with number of 1s equal to digits in n. 
            temp=temp>>1;
        }
        return ~n&mask;
    }
};