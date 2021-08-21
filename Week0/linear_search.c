#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void less_comparison_search(int *arr, int n, int key, FILE* out_fp) {
	int count = 1, fl = 1, i, j, tmp = arr[n-1];
	
	fprintf(out_fp, "Minimum comparison search: \n");
	
	if(tmp == key) {
		fprintf(out_fp, "Found at index: %d\n", n-1);
		return;
	}
	arr[n-1] = key;
	for(i = 0; ; i++) {
		if(count++ && arr[i] == key) {
			if(count++ && i < n-1) {
				fprintf(out_fp, "Fount at index: %d\n", i);
				break;
			}
			
			fprintf(out_fp, "NOT FOUND!\n");
			break;
		}
	}
	arr[n-1] = tmp;
	fprintf(out_fp, "Number of comparisons: %d\n\n", count);
}

void front_and_back_search(int* arr, int n, int key, FILE* out_fp) {
	int count = 1, pos = -1, i, j;
	
	fprintf(out_fp, "Front and back search: \n");
	
	for(i = 0, j = n-1; count++ && i <= j; i++, j--) {
				if(count++ && arr[i] == key) {
					fprintf(out_fp, "Fount at index: %d\n", i);
					pos = i;
					break;
				}
				if(count++ && arr[j] == key) {
					fprintf(out_fp, "Found at index: %d\n", j);
					pos = j;
					break;
				}
			}
			if(pos == -1)
				fprintf(out_fp, "NOT FOUND!\n");
	fprintf(out_fp, "Number of comparisons: %d\n\n", count);
}

void linear_search (int* arr, int n, int key, FILE* out_fp) {
	int count = 1, pos = -1, i;
	fprintf(out_fp, "Linear search: \n");
	for(i = 0; count++ && i < n; i++) {
				if(count++ && arr[i] == key) {
					fprintf(out_fp, "Found at index: %d\n", i);
					pos = i;
					break;
				}
			}
			if(pos == -1)
				fprintf(out_fp, "NOT FOUND!\n");
	fprintf(out_fp, "Number of comparisons: %d\n\n", count);
} 

int main(void) {
	FILE* in_fp = fopen("input.txt", "r"), *out_fp = fopen("output.txt", "w");
	int testCases = 0;

	if(in_fp == NULL) {
		printf("Unable to open input.txt file\n");
	}

	else {
		fscanf(in_fp, "%d", &testCases);
		int t = 1;
		while(testCases--) {
			int arr[SIZE], i, n, key;
		
			fscanf(in_fp,"%d", &n);

			for(i = 0; i < n; i++) {
				fscanf(in_fp, "%d", &arr[i]);
			}
			
			fscanf(in_fp, "%d", &key);
			fprintf(out_fp, "Case #%d:\n\n", t++);
			linear_search(arr, n, key, out_fp);
			front_and_back_search(arr, n, key, out_fp);
			less_comparison_search(arr, n, key, out_fp);
		}
		fclose(in_fp);
		fclose(out_fp);
	}
	return 0;
}
