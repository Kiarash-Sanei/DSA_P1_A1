#include <stdio.h>
#include <stdlib.h>

// A function to generate a beautiful array recursively
void generateBeautifulArray(int n, int *result)
{
    // Base case: if n is 1, the beautiful array is [1]
    if (n == 1)
    {
        result[0] = 1;
        return;
    }

    // Cutting the array into two halves
    int leftSize = (n + 1) / 2;
    int rightSize = n - leftSize;

    int *leftArray = (int *)malloc(leftSize * sizeof(int));
    int *rightArray = (int *)malloc(rightSize * sizeof(int));

    // Generating the beautiful array for the two halves
    generateBeautifulArray(leftSize, leftArray);
    generateBeautifulArray(rightSize, rightArray);

    // Filling the result array with the beautiful array
    for (int i = 0; i < leftSize; i++)
    {
        result[i] = 2 * leftArray[i] - 1;
    }
    for (int i = 0; i < rightSize; i++)
    {
        result[leftSize + i] = 2 * rightArray[i];
    }

    // Freeing the memory allocated for the two halves
    free(leftArray);
    free(rightArray);
}

int main()
{
    int n;
    scanf("%d", &n);

    // Allocate memory for the beautiful array
    int *beautifulArray = (int *)malloc(n * sizeof(int));
    generateBeautifulArray(n, beautifulArray);

    // Printing the beautiful array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", beautifulArray[i]);
    }
    printf("\n");

    // Freeing the memory allocated for the beautiful array
    free(beautifulArray);
    return 0;
}
