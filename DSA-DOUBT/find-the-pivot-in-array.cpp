// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int findpivot (int array[],int n){
    int s=0;
    int e=n-1;
    int mid= (s+((e-s)/2));
    while (s<e){
        if(array[mid]>array[0])
        s=mid+1;
        else
        e=mid;
        mid= (s+((e-s)/2));
    }
    return array[s]; 
}
int main() {
    int arr[6]={3,8,17,1,3,4};
    int pivot = findpivot(arr,6);
    cout<<pivot;
    

    return 0;
//Faced issues initially after learnign the logic. was able to write almost all of the code on my own just made a simple mistake of adding a = sign in if condition. Also we return s and not mid as mid is not calculated after the loop ends which means there is a cahnce that it is diff than the value fo the pivot