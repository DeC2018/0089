#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n; // 2^n elements in the Gray code sequence
    int* result = (int*)malloc(*returnSize * sizeof(int));

    for (int i = 0; i < *returnSize; i++) {
        result[i] = i ^ (i >> 1); // Generate Gray code using the formula
    }

    return result;
}

// Helper function to print the Gray code sequence
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    int n;
    int returnSize;

    // Example 1
    n = 2;
    printf("Input: n = %d\n", n);
    int* result1 = grayCode(n, &returnSize);
    printf("Output: ");
    printArray(result1, returnSize);
    free(result1);

    // Example 2
    n = 1;
    printf("Input: n = %d\n", n);
    int* result2 = grayCode(n, &returnSize);
    printf("Output: ");
    printArray(result2, returnSize);
    free(result2);

    return 0;
}
