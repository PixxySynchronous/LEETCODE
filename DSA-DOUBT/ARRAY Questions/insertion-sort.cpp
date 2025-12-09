#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
  int i=1;
  for (;i<arr.size();i++){
  int j=i-1;
  int temp=arr[i];
      while(j>=0 && arr[j]>temp){
          arr[j+1]=arr[j];
          j--;
      }
    arr[j+1]=temp;
  }
}


//Would require practice to completly nail down the logic of this as i couldnt code it on my own. 