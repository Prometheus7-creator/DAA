#include <stdio.h>

#define N 50

void merge (int arr[], int l, int mid, int r) {
    int i, j, k;

    int nLeft = mid - l+1;
    int nRight = r - mid;

    int leftArray[nLeft], rightArray[nRight];

    for (i = 0; i < nLeft; i++) leftArray[i] = arr[l + i];
    for (j = 0; j < nRight; j++) rightArray[j] = arr[mid + j + 1];

    i = 0; j = 0;
    k = l;

    while (i < nLeft && j < nRight) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i++];
        }
        else {
            arr[k] = rightArray[j++];
        }
        k++;
    }

    while (i < nLeft) arr[k++] = leftArray[i++];
    while (j < nRight) arr[k++] = rightArray[j++];

}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r-l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int t;
    printf("Enter number of test cases: ");
    scanf("%d", &t);

    while (t--) {
        int n,arr[N], fl = 0;
    
	    printf("Enter size of input array(max size-50): ");
	    scanf("%d", &n);
	    printf("Enter elements of the array: ");

	    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        merge_sort(arr, 0, n-1);
        
        for (int i = 0; i < n; i++) {
            if ((i+1) < n && arr[i] == arr[i+1]) {
                fl = 1;
                break;
            } 
        }

        if (fl) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}