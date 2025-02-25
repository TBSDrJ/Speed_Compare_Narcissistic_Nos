#include<stdio.h>
#include<math.h>

const short MAX_DIGITS = 9;

int main() {
    int i, j, n, chars = 0, digs_sz;
    int digs[MAX_DIGITS];
    unsigned long narcissism_sum;

    for (i=1; i<10000000; i++) {
        n = i;
        for (int j=0; j<MAX_DIGITS; j++) {
            digs[j] = n % 10;
            n /= 10;
            if (n == 0) {
                digs_sz = j + 1;
                break;
            }
        }
        narcissism_sum = 0;
        for (j=0; j<digs_sz; j++) {
            narcissism_sum += pow(digs[j], digs_sz);
        }
        if (i == narcissism_sum) {
            printf("%d ", i);
            chars += digs_sz + 1;
            if (chars > 70) {
                printf("\n");
                chars = 0;
            }
        }
    }
    printf("\n");
}