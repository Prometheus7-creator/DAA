#include <stdio.h>
#define N 20
int main() {
	
	int arr[N], n, key, count = 0, l = 0, r;

	printf("Enter length of input array: ");  

        scanf("%d", &n);                          
        
	printf("Enter array elements: ");         
        for (int i = 0; i < n; i++) {                                                              
                scanf("%d", &arr[i]);                                                              
        }                                                                                          
                                                                                                   
        printf("Enter key to found: ");                                                            
        scanf("%d", &key);	 
        
	r = n-1;
	while (l <= r) {
		int mid = l + (r-l) / 2;
		++count;
		if (arr[mid] == key) {
			printf("Number of comparisons: %d", count);
			printf("\n%d is found at postion: %d\n", key, mid);
			return 0;
		} else if (arr[mid] > key) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	
	printf("Number of comparisons: %d", count);
        printf("\n%d is not found\n", key);

	return 0;
}
