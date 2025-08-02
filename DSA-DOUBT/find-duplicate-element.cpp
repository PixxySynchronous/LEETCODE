// You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

// int findDuplicate(vector<int> &arr) 
// {
//     int size= arr.size();
//     for(int i=0;i<size;i++){
//         for (int j=i+1;j<size;j++){
//         if ((arr[i]^arr[j])==0)
//         return arr[i];

//         }
//     }
	
}
// This solution uses a brute force approach with O(N^2) time complexity. Needed a hint to reduce time complexity.

int findDuplicate(vector<int> &arr) 
{
    int ans=0;
    for (int i =0;i<arr.size();i++){
        ans=ans^arr[i];
    }
    for (int i =1;i<arr.size();i++){
        ans=ans^i;
    }
    return ans;
}
//eg if array = 4,2,1,3,1
// here first ans = 0^4^2^1^3^1 
//then ans = 0^1^2^3^4^0^4^2^1^3^1
// which will result in 1 as the duplicate element since all other elements cancel each other out.