#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers, used in qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int N;
        scanf("%d", &N);

        int positions[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &positions[i]);
        }

        // Sort positions to make it easier to calculate clusters
        qsort(positions, N, sizeof(int), compare);

        int minInfected = N;
        int maxInfected = 1;
        int currentClusterSize = 1;

        for (int i = 1; i < N; i++) {
            if (positions[i] - positions[i - 1] <= 2) {
                // If the current person can be infected from the previous person
                currentClusterSize++;
            } else {
                // End of current cluster
                if (currentClusterSize < minInfected) {
                    minInfected = currentClusterSize;
                }
                if (currentClusterSize > maxInfected) {
                    maxInfected = currentClusterSize;
                }
                currentClusterSize = 1;
            }
        }

        // Check the last cluster
        if (currentClusterSize < minInfected) {
            minInfected = currentClusterSize;
        }
        if (currentClusterSize > maxInfected) {
            maxInfected = currentClusterSize;
        }

        // Print results for this test case
        printf("%d %d\n", minInfected, maxInfected);
    }

    return 0;
}

