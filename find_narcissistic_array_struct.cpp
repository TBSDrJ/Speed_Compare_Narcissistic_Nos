#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<ctime>
#include<sstream>

using namespace std;

const short MAX_DIGITS = 9;

struct digits_t {
    unsigned long digits[MAX_DIGITS];
    int size;
};

digits_t get_digits(unsigned long n) {
    digits_t digits;
    for (int i=0; i<MAX_DIGITS; i++) {
        digits.digits[i] = n % 10;
        n /= 10;
        if (n == 0) {
            digits.size = i + 1;
            break;
        }
    }
    return digits;
}

int main() {
    int i, j, chars = 0;
    digits_t digs;
    unsigned long narcissism_sum;
    time_t start;
    ostringstream out_str;
    ofstream fout;

    start = clock();
    for (i=1; i<10000000; i++) {
        digs = get_digits(i);
        narcissism_sum = 0;
        for (j=0; j<digs.size; j++) {
            narcissism_sum += pow(digs.digits[j], digs.size);
        }
        if (i == narcissism_sum) {
            cout << i << " " << flush;
            out_str << i << " ";
            chars += digs.size + 1;
        }
        if (chars > 70) {
            cout << endl;
            out_str << endl;
            chars = 0;
        }
    }
    fout.open("narcissistic_nos_array_struct_cpp.txt", ios::trunc | ios::out);
    fout << out_str.str() << endl;
    fout << "Secs to complete: " << static_cast<float> (clock() - start) / CLOCKS_PER_SEC << endl;
    cout << "Secs to complete: " << static_cast<float> (clock() - start) / CLOCKS_PER_SEC << endl;
    fout.close();
}