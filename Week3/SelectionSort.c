#include <stdio.h>

#define N 50

int main() {
    int n,arr[N], swaps = 0, comparisons = 0;
	
	printf("Enter size of input array(max size-50): ");
	scanf("%d", &n);
	printf("Enter elements of the array: ");

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    for (int i = 0; i < n; i++) {
        
        int min = i;
        for (int j = i+1; j < n; j++) {
            if ((++comparisons) && (arr[j] < arr[min])) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        swaps++;
    }

    printf("Sorted array:");
    
    for (int i = 0; i < n; i++) printf(" %d", arr[i]);
    
    printf("\nNumber of swaps: %d", --swaps);

    printf("\nNumber of comparisons: %d\n", comparisons);

    return 0;
}