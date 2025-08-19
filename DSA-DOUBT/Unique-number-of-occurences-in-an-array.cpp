//Leetcode 1207 // Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

//MY SOLUTION

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int size = arr.size();
        int i;
        int count;
        int j;
        int k=0;
        int occurences[size];
        for (i=0;i<size;i++){
            count =1;
            if(arr[i]==1001)
            continue;
            for (j=i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    arr[j] =1001;
                    count++;
                }
            }
            occurences[k]=count; 
            k++;
        }
        i=0;
        for (i=0;i<k;i++){
            j=i+1;
            cout<<occurences[i]<<" ";
            for(;j<k;j++)
            if(occurences[i]==occurences[j])
            return false; 
        }
        return true;
    }
};

//THIS SOLUTION DID WORK , HOWEVER I FELT THAT THERE HAS TO BE A BETTER WAY TO DO IT. 