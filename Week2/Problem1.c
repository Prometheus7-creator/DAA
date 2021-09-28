#include <stdio.h>
#define N 20

int lastIndex(int arr[], int l, int r, int key, int n) {
	if (r >= l) {
                int mid = l + (r-l) / 2;
                if ((mid == n-1 || key < arr[mid+1]) && arr[mid] == key)
                        return mid;
                else if (key < arr[mid])
                        return lastIndex(arr, l, mid-1, key, n);
                else return lastIndex(arr, mid+1, r, key, n);
        }
        return -1;
}

int firstIndex(int arr[], int l, int r, int key, int n) {
	if (r >= l) {
		int mid = l + (r-l) / 2;
		if ((mid == 0 || key > arr[mid-1]) && arr[mid] == key)
			return mid;
		else if (key > arr[mid])
			return firstIndex(arr, mid+1, r, key, n);
		else return firstIndex(arr, l, mid-1, key, n);
	}
	return -1;
}

int freq(int arr[], int n, int key) {
	int i = firstIndex(arr, 0, n-1, key, n);
	if (i == -1)
		return 0;
	int j = lastIndex(arr, i, n-1, key, n);
	
	return j-i+1;
}

int main() {
	
	int n,arr[N], key, occurences;
	
	printf("Enter size of input array(max size-20): ");
	scanf("%d", &n);
	printf("Enter elements of the array: ");

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	printf("Enter key: ");

	scanf("%d", &key);

	occurences = freq(arr, n, key);

	if (occurences) {
		printf("%d is present in the array.\n", key);
		printf("Occurences: %d\n", occurences);
	}
	else printf("%d is not present in the array.\n", key);

	return 0;
}

