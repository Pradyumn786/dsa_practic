 #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *heat;
    long long sum = 0;
    double avg;
    int max;

    printf("Enter number of heat readings: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size. Please enter a positive number.\n");
        return 1;
    }

    // Dynamic memory allocation for array
    heat = (int *)malloc(n * sizeof(int));

    if (heat == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d heat values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heat[i]);
        sum += heat[i];
    }

    avg = (double)sum / n;
    max = heat[0];

    for (int i = 1; i < n; i++) {
        if (heat[i] > max) {
            max = heat[i];
        }
    }

    printf("\nHeat readings entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", heat[i]);
    }
    printf("\n\nAverage heat = %.2f\n", avg);
    printf("Maximum heat = %d\n", max);

    // Free allocated memory
    free(heat);

    return 0;
}