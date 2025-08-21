// Problem statement
// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

// Note :

// String 'S' is NOT case sensitive.
// Example :

// Let S = “c1 O$d@eeD o1c”.
// If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.

#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{   string filteredstring;
    for (char i:s){
        if (isalnum(i)){
            filteredstring+=tolower(i);
        }
    }

    int start=0;
    int end = filteredstring.size()-1;
    while(start<end){
        if (filteredstring[start]!=filteredstring[end])
        return false; 
        start++;
        end--;
    }
    return true;
}


//Main thing here to see the functions for strings. The for loops , isalnum, tolower. 