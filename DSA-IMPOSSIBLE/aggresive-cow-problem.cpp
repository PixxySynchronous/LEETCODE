// Problem statement
// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



// You are also given an integer 'k' which denotes the number of aggressive cows.



// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



// Print the maximum possible minimum distance.



// Example:
// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

// Output: 2

// Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

bool possiblesol(vector<int> &arr, int k, int mid){
    int lastpost=0;
    int ans=0;
    int cow=1;
    int difference=0;
    for (int i=lastpost+1;i<arr.size();i++){
        difference=arr[i]-arr[lastpost];
        if (difference>=mid){
            cow ++;
            if(cow==k)
            return true; 
            lastpost=i;
          
        }

    }
    return false;
}



int aggressiveCows(vector<int> &arr, int k){
    sort(arr.begin(),arr.end());
    int ans=-1;
    int s=0;
    int e = arr.back() - arr.front();   
    while (s<=e){
        int mid = s + (e-s)/2;
        if (possiblesol(arr,k,mid)){
            s=mid+1;
            ans=mid;
        }
        else {
            e=mid-1;
        }

    }
    return ans;

//Still dont understand the possiblesol logic. 
//Will need to understadn later with a fresher mind. Did understand why we needed to sort the array and the search space.those two ideas i came up with on my own.
// However i could not think of the logic of possiblesol even though i knew i had to implement that method.