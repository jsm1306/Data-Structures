#include <stdio.h>

long long min_value_of_f(int N) {
    if (N % 2 == 0) {
        return ((long long)N / 2) * ((long long)N / 2 + 1);
    } else {
        return (((long long)N / 2) + 1) * (((long long)N / 2) + 1);
    }
}

int main() {
    // Input number of test cases
    int T,i;
    scanf("%d", &T);

    // Iterate through each test case
    for (i = 0; i < T; ++i) {
        // Input size of the permutation
        int N;
        scanf("%d", &N);
        
        // Output the minimum value of f(A)
        printf("%lld\n", min_value_of_f(N));
    }

    return 0;
}
