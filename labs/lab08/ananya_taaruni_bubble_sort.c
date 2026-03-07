/*
Program Name: Bubble Sort

Author: Taaruni Ananya

Progrma Description: This program takes input from the user and sorts it according to the bubble sort method. Then program will then print out the results.
*/

# include <stdio.h>

void bubble_sort(int array[], int n, int *min, int *max);

int main(void) {
    int arr[10];
    int min, max;

    for (int x = 0; x < 10; x++){
        printf("Please enter number %d: ", x + 1);
        scanf("%d", &arr[x]);
    }

    bubble_sort(arr, 10, &min, &max);

    printf("[");
    for (int x = 0; x < 10; x++) {
        if (x < 9) {
            printf("%d, ", arr[x]);
        } else {
            printf("%d", arr[x]);
        }
    }
    printf("]\n");
    printf("Largest: %d\n", max);
    printf("Smallest: %d", min);

}

void bubble_sort(int array[], int n, int *min, int *max) {
    for (int x = 0; x < n - 1; x++) {
        for (int y = 0; y < n - 1 - x; y++) {
            if (array[y] > array[y + 1]) {
                int temp_var = array[y];
                array[y] = array[y + 1];
                array[y + 1] = temp_var;
            }
        }
    }
    *min = array[0];
    *max = array[n - 1];
}