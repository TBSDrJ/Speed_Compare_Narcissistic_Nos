import java.lang.Math;

public class FindNarcissisticNumbers {
    public static void main(String[] args) {
        int d = 0, i = 0, j = 0, n = 0, chars = 0;
        int narcissistic_sum = 0;
        int digits[] = {};
        // long start = System.currentTimeMillis(), end;
        digits = new int[9];
        for (i=1; i<10000000; i++) {
            n = i;
            d = 0;
            while (n > 0) {
                digits[d] = n % 10;
                n /= 10;
                d++;
            }
            narcissistic_sum = 0;
            for (j = 0; j < d; j++) {
                narcissistic_sum += Math.pow(digits[j], d);
            }
            if (i == narcissistic_sum) {
                System.out.print(i);
                System.out.print(" ");
                chars += d + 1;
            }
            if (chars > 70) {
                System.out.println();
                chars = 0;
            }
        }
        // end = System.currentTimeMillis();
        System.out.println();
        // System.out.print("Secs to complete: ");
        // System.out.println((end - start) / 1000.0);
    }
}