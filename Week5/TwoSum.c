#include <stdio.h>

#define N 50

void merge(int arr[], int l, int mid, int r) {
    int i, j, k;
    int nLeft = mid - l+1;
    int nRight = r - mid;

    int leftArray[nLeft], rightArray[nRight];

    for (int i = 0; i < nLeft; i++) leftArray[i] = arr[l + i];
    for (int j = 0; j < nLeft; j++) rightArray[j] = arr[mid + 1 + j];

    i = j = 0;
    k = l;

    while (i < nLeft && j < nRight) {
        if (leftArray[i] <= rightArray[j]) arr[k++] = leftArray[i++];
        else arr[k++] = rightArray[j++];
    }

    while (i < nLeft) arr[k++] = leftArray[i++];
    while (j < nRight) arr[k++] = rightArray[j++];
}


void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r-l)/2;
        
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int t;
    printf("Enter number of testcases: ");
    scanf("%d", &t);
    while (t--) {
        int n,arr[N], target, fl = 0;
    
	    printf("Enter size of input array(max size-50): ");
	    scanf("%d", &n);
	    printf("Enter elements of the array: ");

	    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        printf("Enter target sum: ");
        scanf("%d", &target);

        merge_sort(arr, 0, n-1);

        int l = 0, r = n-1;

        printf("Answer: ");
        while (l < r) {
            int tmp = arr[l] + arr[r];
            if (tmp > target) r--;
            else if (tmp < target) l++;
            else {
                if (fl) printf(", ");
                printf("%d %d", arr[l],arr[r]);
                fl = 1;
                l++;
            }
        }

        if (!fl) printf("No such pairs");

        printf("\n");
    }

    return 0;
}