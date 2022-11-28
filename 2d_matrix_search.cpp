//C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void binarySearch(int a[][MAX], int n, int m, int k, int x)
// x is the row number
{
	// now we simply have to apply binary search as we
	// did in a 1-D array, for the elements in row
	// number
	// x

	int l = 0, r = m - 1, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;

		if (a[x][mid] == k)
		{
			cout << "Found at (" << x << "," << mid << ")" << endl;
			return;
		}

		if (a[x][mid] > k)
			r = mid - 1;
		if (a[x][mid] < k)
			l = mid + 1;
	}
	cout << "Element not found" << endl;
}

void findRow(int a[][MAX], int n, int m, int k)
{

	int l = 0, r = n - 1, mid;

	while (l <= r)
	{
		mid = (l + r) / 2;

		// we'll check the left and
		// right most elements
		// of the row here itself
		// for efficiency
		if (k == a[mid][0]) // checking leftmost element
		{
			cout << "Found at (" << mid << ",0)" << endl;
			return;
		}

		if (k == a[mid][m - 1]) // checking rightmost
								// element
		{
			int t = m - 1;
			cout << "Found at (" << mid << "," << t << ")" << endl;
			return;
		}

		if (k > a[mid][0] && k < a[mid][m - 1])
		// this means the element
		// must be within this row
		{
			binarySearch(a, n, m, k, mid);
			// we'll apply binary
			// search on this row
			return;
		}

		if (k < a[mid][0])
			r = mid - 1;
		if (k > a[mid][m - 1])
			l = mid + 1;
	}
}

//Driver Code
int main()
{
	int n = 4; // no. of rows
	int m = 5; // no. of columns

	int a[][MAX] = {{0, 6, 8, 9, 11},
					{20, 22, 28, 29, 31},
					{36, 38, 50, 61, 63},
					{64, 66, 100, 122, 128}};

	int k = 31; // element to search


	findRow(a, n, m, k);
	
	return 0;
}
// This code is contributed by nirajgusain5
