
/*
Problem Explanation:
We are given a sorted array that has been rotated at an unknown pivot point.
This means the array is no longer fully sorted, but is sorted in two separate parts.
For example, [1, 3, 5, 7, 8] rotated at index 3 becomes [7, 8, 1, 3, 5].
We need to find the index of a given element 'k' in this rotated array.

Key Points:
1. The array contains no duplicates.
2. Rotation is only in the right direction.
3. If 'k' is not present, return -1.
4. The array can be thought of as two individually sorted subarrays joined together.
*/

int findpivot(vector<int>& arr, int n){
    int e=n-1;
    int s=0;
    int mid = s + (e-s)/2;
    while (s<e){
        if (arr[mid]>arr[0]){
            s=mid+1;
        }
        else 
        e=mid;
        mid = s + (e-s)/2;      
    }
    return s; 
}

int binarysearch (vector <int>& arr, int k, int startindex, int endindex){
    int e=endindex;
    int s=startindex;
    int mid = s + (e-s)/2;
    while (s<=e){
        if(k==arr[mid])
        return mid; 

        else if (k>arr[mid])
        s= mid+1; 

        else
        e=mid-1;

        mid = s + (e-s)/2;
    }
    return -1; 
}


int search(vector<int>& arr, int n, int k)
{
    int pivot = findpivot(arr,n);
    if (k==arr[pivot]){
        return pivot;
    }
   
    int ans=  binarysearch(arr,k,pivot,n-1);
    if (ans==-1)
            
    ans = binarysearch(arr,k,0,pivot);
    return ans;
    
}

