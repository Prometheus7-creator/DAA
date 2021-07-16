#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main(void) {
	FILE* in_fp = fopen("input.txt", "r"), *out_fp = fopen("output.txt", "w");
	int testCases = 0;

	if(in_fp == NULL) {
		printf("Unable to open input.txt file\n");
	}

	else {
		fscanf(in_fp, "%d", &testCases);

		while(testCases--) {
			int arr[SIZE], i, count = 1, n, key, fl = 1;
		
			fscanf(in_fp,"%d", &n);

			for(i = 0; i < n && count++; i++) {
				fscanf(in_fp, "%d", &arr[i]);
			}
			count--;

			fscanf(in_fp, "%d", &key);

			for(i = 0; count++ && i < n; i++) {
				if(count++ && arr[i] == key) {
					fprintf(out_fp, "FOUND!\n");
					fl = 0;
					break;
				}
			}
			if(fl)
				fprintf(out_fp, "NOT FOUND!\n");
			fprintf(out_fp, "Number of comparisons: %d\n", count);
		}
		fclose(in_fp);
		fclose(out_fp);
	}
	return 0;
}
