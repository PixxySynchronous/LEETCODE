// LEETCODE-283 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy 
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
//         //approach: search left of the element, if 0 present swap, then search again, sort of like bubble sort to get 0 out. 

//         for (int i =1;i<arr.size();i++){
//             if (arr[i]==0)
//             continue; 
//             int j=i-1;
//             while(j>=0){
//                 if(arr[j]==0) {
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;}
//                 j--;
//             }
//         }
// }


    int nonzero = 0 ; 
    int i=0; 
    while (i<arr.size()){
        if (arr[i]!=0){
            swap(arr[nonzero],arr[i]);
            nonzero++;
        }
        i++;

    
}}
};
        
    

//My solution was unnecesarrily complicated and the actual answer is much simpler and easier to think of, but glad i could come up with an answer after all. Needed one help to dry run the code via gpt to find a bug though. 