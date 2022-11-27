#include <bits/stdc++.h>
using namespace std;

void merge(int *arr1, int n, int *arr2, int m){
    int k = n-1;
    int i = n - m - 1;
    int j = m - 1;
    for(; i >= 0 && j >= 0 && k >= 0; ){
        if(arr1[i] > arr2[j]){
            arr1[k--] = arr1[i--];
        } else{
            arr1[k--] = arr2[j--];
        }
    }
    while(i > 0){
        arr1[k--] = arr1[i--];
    }
    while(j > 0){
        arr1[k--] = arr2[j--];
    }
}

void print_arr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    print_arr(arr, 5);
    print_arr(arr2, 5);
    merge(arr, 10, arr2, 5);
    print_arr(arr, 10);
    return 0;   
}