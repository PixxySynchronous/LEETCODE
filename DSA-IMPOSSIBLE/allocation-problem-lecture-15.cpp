// Problem statement
// Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



// There are ‘m’ number of students, and the task is to allocate all the books to the students.



// Allocate books in such a way that:

// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.


// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



// If the allocation of books is not possible, return -1.

bool possiblesol (vector<int>& arr, int n, int m, int mid){
    int sum=0;
    int i=0;
    int students=1; 
    for(;i<n;i++){
        if (sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            students++;
            if(arr[i]>mid||students>m){
            return false; 
            }
        sum=arr[i];}
    
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
      if (m > n) return -1;
    int sum=0;
    int ans=-1;
    for (int i=0;i<n;i++){
        sum+=arr[i];
    }
    int s=0;
    int e=sum;
    int mid = s + (e-s)/2;
    while(s<=e){
        if (possiblesol(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else 
        s=mid+1;
        mid= s + (e-s)/2;
    }
    return ans; 
}


//Had to see the logic and the code to solve this one...needs rehearsal and repetition to understand fully.
//Was able to successfully (almost) do the painters allocation problem which uses the same approach.