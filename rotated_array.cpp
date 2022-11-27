#include <bits/stdc++.h>
using namespace std;

int search(int *arr, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return -1;
    }
    if (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[start] <= arr[mid])
        {
            if (target >= arr[start] && target < arr[mid])
            {
                return search(arr, target, start, mid - 1);
            }
            else
            {
                return search(arr, target, mid + 1, end);
            }
        }
        if(target > arr[mid+1] && target < arr[end])
        {
            return search(arr, target, mid + 1, end);
        }
    }
    return search(arr, target, start, mid);
}
int main()
{
    int n = 12;
    int arr[n] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target = 16;
    cout << search(arr, target, 0, n - 1) << endl;
    return 0;
}