#include <stdio.h>
#define N 50

int partition(int arr[], int l, int r) {
    int pivot = arr[r], temp;

    int j = l-1;
    for (int i = l; i <= r-1; i++) {
        if (arr[i] < pivot) {
            temp = arr[i];
            arr[i] = arr[++j];
            arr[j] = temp;
        }
    }
    temp = arr[j+1];
    arr[j+1] = arr[r];
    arr[r] = temp;
    return j+1;
}

void quick_sort(int arr[], int l, int r) {
    if (l < r) {
        int pivot = partition(arr, l, r);

        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, r);
    }
}

int main() {
    int n,arr[N];
	
	printf("Enter size of input array(max size-50): ");
	scanf("%d", &n);
	printf("Enter elements of the array: ");

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    quick_sort(arr, 0, n-1);

    printf("Sorted Array:");

    for (int i = 0; i < n; i++) printf(" %d", arr[i]);

    printf("\n");

    return 0;
}