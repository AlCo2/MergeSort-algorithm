#include <stdio.h>


void mergesort(int arr[],int arrsize);
void rec(int arr[], int l, int r);
void sort(int arr[], int l,int m,int r);

int main(){
    int arr[] = {2,5,3,1,7,6,4,9,8,0,454,21,67,89};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<arrSize;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergesort(arr, arrSize);
    for(int i=0;i<arrSize;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergesort(int arr[],int arrsize){
    rec(arr, 0 , arrsize-1);
};
void rec(int arr[], int l,int r){
    if(l<r){
        int m = l + (r-l) / 2;
        rec(arr, l, m);
        rec(arr, m+1, r);
        sort(arr, l, m, r);
    }
}

void sort(int arr[], int l,int m,int r){
    int left_lenght = m-l+1;
    int right_lenght = r-m;
    int left[left_lenght];
    int right[right_lenght];
    int i,j,k;
    for(i=0;i<left_lenght;i++)
        left[i] = arr[i+l];
    for(i=0;i<right_lenght;i++)
        right[i] = arr[m+1+i];
    i=0;
    j=0;
    for(k=l;k<=r;k++){
        if((i<left_lenght) && (j>=right_lenght || left[i]<= right[j])){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
    }

}
