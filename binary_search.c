#include <stdio.h>

const int c = 8;

int search(int arr[], int target, int left, int right){
    int m = (left+right)/2;
    if(arr[m]>target){
        search(arr,target,left,m-1);
    }if(arr[m]<target){
        search(arr,target,m+1,right);
    }
    else{
    return m;
    }}


int main(){
    int arr[8] = {1,2,3,4,5,6,7,8};
    printf("%d", search(arr,8,0,c));
    return 0;
}