// For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.

// For eg:-

// The sine wave for the matrix:-
// 1 2
// 3 4
// will be [1, 3, 4, 2].

#include <bits/stdc++.h> 
using namespace std; 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector <int> ans; 
    for (int j = 0 ; j< mCols ; j++){
        if (j%2==0){
            int i = 0 ; 
            while (i<nRows){
            ans.push_back(arr[i][j]);
            i++;
            }
        }
        else{
            int i = nRows -1 ;
            while (i>=0){
            ans.push_back(arr[i][j]);
            i--; 
            }
        }git 


    }
    return ans; 
    }
