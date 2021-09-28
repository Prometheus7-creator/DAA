#include <stdio.h>
#include <math.h>
#define N 20


int main() {
	
	int n, arr[N], key, c = 0;
	
	printf("Enter the size of input array(max size: 20): ");
	scanf("%d", &n);
	printf("Input array: ");

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	printf("Enter key: ");
	scanf("%d", &key);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if ((arr[i] - arr[j]) == key)
					c++;
			}
		}
	}

	printf("Answer: %d\n", c);

	return 0;
}
