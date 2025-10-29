# include <stdio.h>
# define N 5

int main () {

int item = 8;
int found = 0;
int i;

 int numb [N] = {5,6,7,8,9};

    for (i = 0; i < N; i++) {

        if (numb [i] == item) {
            printf("item found %d at index %d", item, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("not found");
    }


    return 0;
}
