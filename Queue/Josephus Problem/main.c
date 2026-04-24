#include <stdio.h>
#include "queue.h"

int main() {
    int n, k;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter step size: ");
    scanf("%d", &k);

    int survivor = josephus(n, k);

    printf("Survivor: %d\n", survivor);

    return 0;
}