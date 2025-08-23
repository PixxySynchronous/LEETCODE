// You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.

// Note:

// 1. The length of each array is greater than zero.

// 2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.

// 3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.

#include <bits/stdc++.h> 
using namespace std; 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// [9,9,9] + [9,9,9] = [1,9,9,8]
	int indexa = n-1;
	int indexb = m-1; 
	vector <int> ans;
	int carry=0;
	
	while (indexa>=0 && indexb>=0){
		int sum =a[indexa] + b [indexb]+carry;		
		ans.push_back(sum%10);
		carry=sum/10;
		indexa --;
		indexb --;

	}
    while (indexa >= 0) {
        int sum = a[indexa] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
        indexa--;
    }

    while (indexb >= 0) {
        int sum = b[indexb] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
        indexb--;
    }

    if (carry) ans.push_back(carry);
	reverse(ans.begin(), ans.end());
	return ans; 
}


//This questio was supposed to be easy but i wasn't well versed with the carry subject and hence did not think of it. My initial thought was of combining the digitd to form the number and then putting the digits abck into sum. My second apporach was similar to this however i didnt have a carry variable and handeled carry through a precarious method causing it to fail many test cases so i caved in and saw the logic and wrote the code. 