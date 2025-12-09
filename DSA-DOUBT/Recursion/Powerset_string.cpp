#include <bits/stdc++.h> 
void solve (string str, string output, vector <string> &ans, int index){
	if (index >= str.length()){
		if (output.length()>0)
		ans.push_back(output);
		return; 
	}
	solve (str,output, ans, index+1); 
	char character  = str[index];
	output.push_back(character); 
	solve (str,output, ans, index +1); 
	output.pop_back(); 

}
vector<string> subsequences(string str){
	string output = ""; 
	vector <string> ans; 
	int index =0 ; 
	solve (str, output, ans, index); 
	return ans; 

	
}
