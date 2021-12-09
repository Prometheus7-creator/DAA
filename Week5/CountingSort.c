#include<stdio.h>
#include<string.h>
#define N 27
#define MAX 100

void solution() {
    int n, i, j, count[N];
    char arr[N], output[N], tmp[MAX];

    printf("Enter size of input array: ");
    scanf("%d", &n);
    printf("Input array: ");
    getchar();
    fgets(tmp, MAX, stdin);
    
    for (i = 0, j = 0; i < n; j++) {
        if (tmp[j] != ' ') {
            arr[i++] = tmp[j];
        }
    }
    for (i = 0; i < N; i++) count[i] = 0;
    for (i = 0; arr[i]; i++) ++count[arr[i]-'a'];

    int mx = 0;
    char mostOccuredElement;
    for (i = 0; i < n; i++) {
        int t = count[arr[i]-'a'];
        if (t > mx) {
            mx = t;
            mostOccuredElement = arr[i];
        }
    }

    if (mx > 1) {
        printf("Max occured element: %c\n", mostOccuredElement);
        printf("Count: %d\n", mx);
    }
    else printf("No duplicate\n");
}

int main() {
    int t;
    printf("Enter number of testcases: ");
    scanf("%d", &t);
    while(t--) solution();
    return 0;
}