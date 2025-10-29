#include <stdio.h>

void addThirdElement(int arr[], int value, int *n) {
    int i;
    if(*n >= 5) {
        printf("Array is full, cannot add more elements.\n");
        return;
    } else {
        for(i = *n; i > 2; i--) {
        }
    }
}

void deleteElement(int arr[], int *n, int pos) {
    int i;

    if(pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    for(i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

void display(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 3; 

    printf("Array before deletion:\n");
    display(arr, n);

    deleteElement(arr, &n, pos);

    printf("Array after deleting 3rd element:\n");
    display(arr, n);

    return 0;
}
