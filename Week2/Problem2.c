#include <stdio.h>

#define N 20

int main() {
	
	int n, arr[N], a, b, c;
	a = b = c = -1;

	printf("Enter the size of input array (max size: 20): ");
	scanf("%d", &n);
	printf("Input sorted array: ");

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		int sum = arr[n-i-1];
		int l = 0;
		int r = n-i-2;

		while (l < r) {
			int chk = arr[l] + arr[r];
			if (chk == sum) {
				a = l;
				b = r;
				c = n-i-1;
				break;
			}
			else if (chk > sum) r--;
			else l++;
		}
	}

	if (a != -1) {
		printf("Answer: %d %d %d\n", a, b, c);
		return 0;
	}

	printf("No such indexes\n");

	return 0;
}
