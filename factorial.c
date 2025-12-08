#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        return -1; 
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int result = factorial(n);

    if (result == -1) {
        printf("Factorial of negative numbers is not defined.\n");
    } else {
        printf("Factorial is %d\n", result);
    }

    return 0;
}
