#include <bits/stdc++.h>
using namespace std;

int search_max(vector<int> arr, int start, int end){
    if(start == end){
        return arr[start];
    }
    while(start <= end){
            int mid = start + (end-start)/2;

        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return arr[mid];
        }
        else if(arr[mid] < arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
}
int main()
{
    vector<int> arr = {1, 7, 14, 26, 38, 45, 26, 11, 9, 3, 1, 0};
    cout << search_max(arr, 0, arr.size() - 1);
    return 0;
}