#include <stdio.h>
#define N 20
int main() {
	
	int arr[N], n, key, count = 0;
	printf("Enter length of input array: ");

	scanf("%d", &n);

	printf("Enter array elements: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter key to found: ");
	scanf("%d", &key);

	for (int i = 0; i < n; i++) {
		++count;
		if (arr[i] == key) {
			printf("\nNumber of Comparisons: %d", count);
			printf("\n%d is present at position: %d\n", key, i);
			return 0;	
		}
	}

	printf("\nNumber of Comparisons: %d", count);
	printf("\n%d is not present in array\n", key);

	return 0;
}
