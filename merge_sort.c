#include <stdio.h>
const int c = 8;

void print_array(int arr[],int len){
    for(int i =0;i<len;i++){
        printf(" %d",arr[i]);
}printf("|");}

void merge(int arr[], int left, int mid, int right){
    const int len = right-left;
    int i = left;int j = mid+1;int k=left;int arr_aux[len];
    for(int i=left;i<=right;i++){
        arr_aux[i] = arr[i];
    }i=left;
    while(i<=mid && j<=right){
        if(arr_aux[i]<=arr_aux[j]){
            arr[k] = arr_aux[i];
            i++;
        }else{
            arr[k] = arr_aux[j];
            j++;}
    k++;}
    while(i<=mid){arr[k]=arr_aux[i];i++; k++;}
    while(j<=right){arr[k]=arr_aux[j];j++; k++;}
    print_array(arr,len);
}

void merge_sort(int arr[], int left, int right){
    if(right<=left){
        return;
    }else{
        int mid = (right+left)/2;
        merge_sort(arr,left,mid);
        merge_sort,(arr,mid+1,right);
        merge(arr,left,mid,right);}
}

int main(){
    int arr[]={1,8,5,6,2,4,7,3};
    merge_sort(arr,0,c);
    print_array(arr,c);
    return 0;
}