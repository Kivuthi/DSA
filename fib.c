#include <stdio.h>

int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n = 2;

    int result = fib(n);
    printf("Fib is %d\n", result);

    return 0;
}
