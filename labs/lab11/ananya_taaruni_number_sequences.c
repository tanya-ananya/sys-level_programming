/*
Program Name: Number Sequences

Author: Taaruni Ananya

Progrma Description: This program takes input from the user and returns each number's Fibonacci sequence, then concatenates all outputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* Fibonacci(int n) {
    int* sequence = (int*)malloc(sizeof(int) * n);

    if (sequence == NULL) {
        return NULL;
    }
    if (n > 0) {
        sequence[0] = 0;
    }
    if (n > 1) {
        sequence[1] = 1;
    }
    for (int x = 2; x < n; ++x) {
        sequence[x] = sequence[x-1] + sequence[x - 2];
    }

    return sequence;
}

int* Squares(int n) {
    int* sequence = (int*)malloc(sizeof(int) * n);

    if (sequence == NULL) {
        return NULL;
    }

    for (int x = 0; x < n; ++x) {
        int val = x + 1;
        sequence[x] = val * val;
    }

    return sequence;
}

int* Concatenate(int* array1, int size1, int* array2, int size2) {
    int* sequence = (int*)malloc(sizeof(int) * (size1 + size2));
        
    if (sequence == NULL) {
        return NULL;
    }

    for (int x = 0; x < size1; ++x) {
        sequence[x] = array1[x];
    }
    for (int x = 0; x < size2; ++x) {
        sequence[size1 + x] = array2[x];
    }

    return sequence;
}

void PrintArray(int* array, int size) {
    for (int x = 0; x < size; ++x) {
        if (x > 0) {
            printf(" ");
        }
        printf("%d", array[x]);
    }
    printf("\n");
}

int main(void) {
    int fibonacci_num;
    int square_num;

    printf("Enter numbers here: ");

    if (scanf("%d %d", &fibonacci_num, &square_num) != 2) {
        return 1;
    }

    int* fibonacci = Fibonacci(fibonacci_num);
    int* squares = Squares(square_num);
    int* concatenated = Concatenate(fibonacci, fibonacci_num, squares, square_num);

    if (fibonacci != NULL) {
        PrintArray(fibonacci, fibonacci_num);
    }
    if (squares != NULL) {
        PrintArray(squares, square_num);
    }
    if (concatenated != NULL) {
        PrintArray(concatenated, fibonacci_num + square_num);
    }

    free(fibonacci);
    free(squares);
    free(concatenated);

    return 0;
}