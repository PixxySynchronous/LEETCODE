// Problem statement
// You are given a string 'str' of length 'N'.



// Your task is to reverse the original string word by word.



// There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.



// Example :
// If the given input string is "Welcome to Coding Ninjas", then you should return "Ninjas Coding to Welcome" as the reversed string has only a single space between two words and there is no leading or trailing space.


string revstring (string &str, int startindex, int endindex){
	char temp;
	while(startindex<endindex){
		temp=str[startindex];
		str[startindex]=str[endindex];
		str[endindex]=temp;
		startindex++;
		endindex--;
	}
	return str; 
}


string reverseString(string &str){
	for (int i = 0; i + 1 < str.size(); i++) {
    if (str[i] == ' ' && str[i+1] == ' ') {
        str.erase(i+1, 1);
        i--; // step back to check again in case of multiple spaces
    }
}

	// Remove leading spaces
	while (!str.empty() && str[0] == ' ') {
    	str.erase(0, 1);
	}

	// Remove trailing spaces
	while (!str.empty() && str[str.size()-1] == ' ') {
    	str.erase(str.size()-1, 1);
	}

	str = revstring(str,0,str.size()-1);
	//reverse the whole string now reversing each word separtely, using the space char as a separator. 
	int wordcounter = 0;

	for (int i=0;i<=str.size();i++){
		if (str[i]==' '|| i==str.size()){ //The only 2 boundary conditions where a word may end 
			str=revstring(str,wordcounter,i-1); 
			wordcounter=i+1;
		}
	}

	return str; 
}


//I got the approachr right of reversing the whole string and then reversign words. The logic to find words was tough to crack and i couldnt do it. I tried several methods but failed. While i did come up with other logics like firstly removing all the spaces in the string first, but even there i failed ot analuze the i-- aspect or even the removal of leading and trailing spaces wasnt thought by me. When i did get the logic fro ai i was stunned at how easily it was overlooked by me. 