#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<ctime>
#include<sstream>
#include"queue_template.cpp"

using namespace std;

const short MAX_DIGITS = 9;

Queue<int> get_digits(int n) {
    Queue<int> digits;
    for (int i=0; i<MAX_DIGITS; i++) {
        enqueue(&digits, n % 10);
        n /= 10;
        if (n == 0) break;
    }
    return digits;
}

int main() {
    int i, j, chars = 0, dig_sz;
    Queue<int> digs;
    unsigned long narcissism_sum;
    time_t start;
    ostringstream out_str;
    ofstream fout;

    start = clock();
    for (i=1; i<10000000; i++) {
        digs = get_digits(i);
        dig_sz = digs.size;
        narcissism_sum = 0;
        for (j=0; j<dig_sz; j++) {
            narcissism_sum += pow(dequeue(&digs), dig_sz);
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
    // fout.open("narcissistic_nos_queue_cpp.txt", ios::trunc | ios::out);
    // fout << out_str.str() << endl;
    // fout << "Secs to complete: " << static_cast<float> (clock() - start) / CLOCKS_PER_SEC << endl;
    // cout << "Secs to complete: " << static_cast<float> (clock() - start) / CLOCKS_PER_SEC << endl;
    // fout.close();
}