class Solution {
public:
    int dayOfYear(string date) {
        int days [] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
        int year = stoi(date.substr(0,4)); 
        int month = stoi (date.substr(5,2)); 
        int day = stoi (date.substr(8,2)); 
        bool leap = false;
        int dayNumber = 0 ;  
        if ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))
                    leap = true; 
        for (int i = 0 ; i<month - 1; i++){
            if (i==1 && leap ==true){
                dayNumber+=days[i]+1; 
            }
            else 
                dayNumber += days[i]; 
        }
        dayNumber += day; 
        return dayNumber;
    }
};