// Problem statement
// You are given a positive integer ‘n’.



// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).



// Example:
// Input: ‘n’ = 7

// Output: 2

// Explanation:
// The square root of the number 7 lies between 2 and 3, so the floor value is 2.



long long int squareroot(int n){
    int s =0;
    int e=n;
   long long int ans=-1; 
   long long  int mid = s + (e-s)/2;
    while (s<=e){
        long long int square=mid*mid;
        if (square==n){
        ans=mid;
        break;}
        else if (square<n){
        ans=mid;
        s=mid+1;}
        else 
        e=mid-1;
        mid=s + (e-s)/2;
    }
    return ans;
}

long long int floorSqrt(int n)
{
    return squareroot(n);
}


//FACED OVERFLOW PROBLEM AND HAD TO LOOK IT UP TO GET LONG LONG INT. OTHERWISE AFTER THE LOGIC BEING TOLD IN THE VIDOE I WAS ABLE TO CODE IT MYSELF. 