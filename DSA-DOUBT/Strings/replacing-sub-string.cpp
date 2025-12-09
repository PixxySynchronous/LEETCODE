// Problem statement
// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.

#include <bits/stdc++.h> 
// #include <iostream>
// string shiftAll(int startingelem,string &str){
// 	str.resize(str.size()+2);
// 	int i = startingelem;
// 	for (int j = str.size()-2; j >= i ; j--){
// 		str[j+2]=str[j];
// 	}
// 	return str;
// }
string replaceSpaces(string &str){
	// for(int i = 0; i< str.size(); i++){
	// 	// std::cout<<i;
	// 	if (str[i]==' '){
	// 		shiftAll(i+1,str);
	// 		str[i]='@';
	// 		str[i+1]='4';
	// 		str[i+2]='0';
	// 	}
	// 	else continue;
	// }
	//Initial solution works. I calla function which makes spce for @40 and then insert it. However worst case time complexity is
	// o(n^2) which made it fail large test cases. 
	//Much simpler solution suggested by gpt:

	string result ="";
	for (char i: str){
		if(i==' ')
		result+="@40";
		else
		result+=i;
	}
	return result;  


// Upon learning new methods i also thought of using replace function and do this 
//    for (size_t i = 0; i < str.length(); i++) {
//         if (str[i] == ' ') {
//             str.replace(i, 1, "@40");  // replace 1 char at position i
//             i += 2; // move index forward (since "@40" is 3 chars, we already consumed 1, so skip 2 more)
//         }
//     }
//     return str;
// }
//AI says this is still ineffecient for large strings.