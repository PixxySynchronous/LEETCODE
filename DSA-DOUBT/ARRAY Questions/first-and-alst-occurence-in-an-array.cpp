// Problem statement
// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



// Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.



// Note :
// 1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
// 2. 'arr' may contain duplicate elements.


// Example:
// Input: 'arr' = [0,1,1,5] , 'k' = 1

// Output: 1 2

// Explanation:
// If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.


int lowerindex (vector<int>& arr, int n, int k){
    int s=0,e=n-1;
    int ans=-1; 
    int mid=(s + (e-s)/2);
    while (s<=e){
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if (arr[mid]<k){
            s=mid+1;
        }
        else {
        e=mid-1;}
        mid=(s + (e-s)/2);

    }
    return ans; 
}

int upperindex (vector<int>& arr, int n, int k){
    int s=0,e=n-1;
    int ans=-1; 
    int mid=(s + (e-s)/2);
    while (s<=e){
        if(arr[mid]==k){
            ans=mid;
            s=mid+1;
        }
        else if (arr[mid]<k){
            s=mid+1;
        }
        else {
        e=mid-1;}
        mid=(s + (e-s)/2);

    }
    return ans; 
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int firstpos= lowerindex(arr,n,k);
    int lastpos= upperindex(arr,n,k);
    return {firstpos, lastpos};
}


//My initial solution was simpler and involved the 2 pointer approach. however this meant a time complexity of O(n) in the worst case. Since the question proposed a constraint of O(log n) i saw the solution from the video and then after many hours implemented the logic myself.
