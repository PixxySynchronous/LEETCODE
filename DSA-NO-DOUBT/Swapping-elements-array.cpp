 #include <iostream>
using namespace std;
void swaparray(int array[],int size){
    int i=0;
    for (i=0;i<size;i=i+2){
        if (i+1==size)
        break;
     int temp=array[i];
     array[i]=array[i+1];
     array[i+1]=temp;
    }
    for (int j=0;j<size;j++){
        cout<<" "<<array[j]<<" ";
    }
}
int main(){
    int numbers[]={2,4,6,8,11,12};
    swaparray(numbers,6);
    return 1;
}