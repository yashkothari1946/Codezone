//Searching Algo
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
          return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int interpolationSearch(int arr[], int n, int x) {
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}
int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    // int result = binarySearch(arr, 0, n - 1, x);
    // (result == -1) ? printf("Element is not present in array"): printf("Element is present at index %d", result);
    int index = interpolationSearch(arr, n, x);
    if (index != -1)
       cout << "Element found at index " << index<<"\n";
   else
       cout << "Element not found.\n";
    return 0;
}
