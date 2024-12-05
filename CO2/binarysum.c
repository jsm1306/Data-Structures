#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N,i;
        scanf("%d", &N);

        int *legs = (int *)malloc(N * sizeof(int));
        if (legs == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }

        for (i = 0; i < N; ++i) {
            scanf("%d", &legs[i]);
        }

        // Sort the legs array in ascending order
        sort(legs, N);

        int maxWeight = 0;
        for (i = N - 1; i >= 0; --i) {
            int totalWeight = legs[i] * (N - i);
            maxWeight = maxWeight > totalWeight ? maxWeight : totalWeight;
        }

        printf("%d\n", maxWeight);

        free(legs);
    }

    return 0;
}

