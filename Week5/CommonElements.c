#include <stdio.h>

#define N 50

int main() {
    int n, m, i, j, k, a[N], b[N], c[N];

    printf("Enter lenght of first array: ");
    scanf("%d", &n);
    printf("input array: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter length of second array: ");
    scanf("%d", &m);
    printf("input array: ");
    for (i = 0; i < m; i++) scanf("%d", &b[i]);

    i = 0; j = 0; k = 0;

    while (i < n && j < m) {
        if (a[i] > b[j]) j++;
        else if (a[i] < b[j]) i++;
        else {
            c[k++] = a[i++];
            j++;
        }
    }

    printf("Answer:");

    for (i = 0; i < k; i++) printf(" %d", c[i]);
    printf("\n");

    return 0;
}