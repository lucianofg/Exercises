#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    long long n;
    scanf("%lld", &n);

    int quant = 0;
    while (n > 0) {
        if (n % 2 == 1)
            quant++;
        n = n / 2;
    }

    long long res = pow(2, quant);

    printf("%lld\n", res);
    return 0;
}
