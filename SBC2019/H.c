#include <math.h>
#include <stdio.h>

int main(void) {
    int v, n;
    scanf("%d %d", &v, &n);
    int res[20] = {0};

    for (int i = 1; i < 10; i++) {
        res[i - 1] = ceil((v * n) * i * 0.1);
        printf("%d", res[i - 1]);
        if (i != 9)
            printf(" ");
    }

    printf("\n");
    return 0;
}
