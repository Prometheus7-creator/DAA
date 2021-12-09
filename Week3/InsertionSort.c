#include <stdio.h>
#define N 50

int main() {
    int n,arr[N], shifts = 0, comparisons = 0;
	
	printf("Enter size of input array(max size-50): ");
	scanf("%d", &n);
	printf("Enter elements of the array: ");

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && temp <= arr[j] && (++comparisons)) {
            arr[j+1] = arr[j];
            shifts++;
            j--;
        }
        arr[j+1] = temp;
        shifts++;
    }

    printf("Sorted array:");
    for (int i = 0; i < n; i++) printf(" %d", arr[i]);
    
    printf("\nNumber of shifts: %d", shifts);

    printf("\nNumber of comparisons: %d", comparisons);

    return 0;
}