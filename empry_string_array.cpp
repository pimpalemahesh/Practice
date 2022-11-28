#include <bits/stdc++.h>
using namespace std;
int search(string strings[], string str, int first, int last)
{
    if (first > last)
        return -1;
    int mid = (last + first) / 2;
    if (strings[mid] == "")
    {
        int left = mid - 1;
        int right = mid + 1;
        while (true)
        {
            if (left < first && right > last)
            {
                return -1;
            }
            else if (right <= last && strings[right] != "")
            {
                mid = right;
                break;
            }
            else if (left >= first && strings[left] != "")
            {
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }
    if (str == strings[mid])
    {
        return mid;
    }
    else if (strings[mid] < str)
    {
        return search(strings, str, mid + 1, last);
    }
    else
    {
        return search(strings, str, first, mid - 1);
    }
}
int main()
{
    int n = 12;
    string arr[n] = {"at", "", "", "ball", "", "", "cat", "", "", "dad", "", ""};
    cout << search(arr, "ball", 0, n - 1);
    return 0;
}
