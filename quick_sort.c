#include <stdio.h>

const int k = 12;

int partition(int arr[], int start,int end){
    int pivot = arr[end];
    while(start<end){
        while(start<end && pivot>=arr[start]){
            start++;
        }
        while(start<end && pivot<arr[end]){
            end--;
        }
        int key = arr[start];
        arr[start] = arr[end];
        arr[end] = key;
    }
    return start;
}

int partition1(int arr[], int start,int end){
    int i=start;
    int pivot = arr[i];
    for(int j=start+1;j<end;j++){
        if(arr[j]<=pivot){
            i++;
            int key = arr[i];
            arr[i] = arr[j];
            arr[j] = key;}}
    int key = arr[i];
    arr[i] = pivot;
    arr[start] = key;
    return i;
}

void quick_sort(int arr[], int start, int end){
    if(start<end){
        int p = (start+end)/2;
        int key = arr[p];
        arr[p] = arr[end];
        arr[end] = key;
        int pos = partition1(arr,start,end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos,end);
}
    else{
        return;
}}

void quick_sort1(int arr[], int start, int end){
    if(end>start){
        int pivot = partition1(arr,start,end);
        quick_sort1(arr,start,pivot);
        quick_sort1(arr,pivot+1,end);
    }
}

void print_array(int arr[],int len){
    for(int i =0;i<len;i++){
        printf(" %d",arr[i]);
}}

int main(){
    int arr[12] ={1,2,3,4,5,6,7,8,9,10,11,12};
    quick_sort1(arr,0,12);
    print_array(arr,12);
}