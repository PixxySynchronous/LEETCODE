
#include <iostream>
using namespace std; 
void rowsum(int arr[][4] , int row , int col){
    int sum [row] = {0};
    for (int i =0 ; i< row ; i++){
        for (int j=0 ; j < col ; j++){
            sum[i]+=arr[i][j];
        }
    }
    for (int i = 0 ; i < row ; i++){
        cout<< "Sum of row " << i+1 << " is " << sum[i] << endl  ; 
    }
}
int main() {
   int arr [3][4] = {1,2,3,4,5,6,7,87,9,10,11,12};
   for (int i=0;i<3;i++){
       for (int j= 0; j< 4; j++){
           cout<< " " <<  arr [i][j]; 
       }
       cout<< endl; 
       
   }
   rowsum (arr,3,4); 

    return 0;
}