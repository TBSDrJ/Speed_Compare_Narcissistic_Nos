#include<math.h>
#include<stdbool.h>
#include<stdio.h>

const short MAX_DIGITS = 9;

int check_narcissistic (int n) {
    int j, digs_sz, target = n;
    int digs[MAX_DIGITS];
    unsigned long narcissism_sum;

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
    if (target == narcissism_sum) {
        return true;
    } else {
        return false;
    }
    // return narcissism_sum;
}
