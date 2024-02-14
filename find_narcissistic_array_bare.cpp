#include<iostream>
#include<cmath>

using namespace std;

const short MAX_DIGITS = 9;

int main() {
    int i, j, n, chars = 0, digs_sz;
    int digs[MAX_DIGITS];
    unsigned long narcissism_sum;
    time_t start;
    ostringstream out_str;
    ofstream fout;

    start = clock();
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
            cout << i << " " << flush;
            out_str << i << " ";
            chars += digs_sz + 1;
            if (chars > 70) {
                cout << endl;
                out_str << endl;
                chars = 0;
            }
        }
    }
    fout.open("narcissistic_nos_arr_bare_O2_cpp.txt", ios::trunc | ios::out);
    fout << out_str.str() << endl;
    fout << "Secs to complete: " << static_cast<float> (clock() - start) / CLOCKS_PER_SEC << endl;
    cout << "Secs to complete: " << static_cast<float> (clock() - start) / CLOCKS_PER_SEC << endl;
    fout.close();
}