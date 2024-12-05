#include <stdio.h>

#define maxsize 100
int i,j;
int main() {
    int vertices;
    int arr[maxsize][maxsize];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (0 for not connected, 1 for connected):\n");
    for ( i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Connected edges:\n");
    for (i = 1; i <= vertices; i++) {
        for (j = i + 1; j <= vertices; j++) {
            if (arr[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }

    return 0;
}

