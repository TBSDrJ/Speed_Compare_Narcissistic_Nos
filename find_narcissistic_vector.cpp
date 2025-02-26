#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<ctime>
#include<sstream>

using namespace std;

vector<unsigned long> get_digits(unsigned long n) {
    vector<unsigned long> digits;
    do {
        digits.push_back (n % 10);
        n /= 10;
    } while (n > 0);
    return digits;
}

int main() {
    int i, j, sz, chars = 0;
    vector<unsigned long> digs;
    unsigned long narcissism_sum;
    time_t start;
    ostringstream out_str;
    ofstream fout;

    start = clock();
    for (i=1; i<10000000; i++) {
        digs = get_digits(i);
        sz = digs.size();
        narcissism_sum = 0;
        for (j=0; j<sz; j++) {
            narcissism_sum += pow(digs[j], sz);
        }
        if (i == narcissism_sum) {
            cout << i << " " << flush;
            out_str << i << " ";
            chars += sz + 1;
        }
        if (chars > 70) {
            cout << endl;
            out_str << endl;
            chars = 0;
        }
    }
    // fout.open("narcissistic_nos_vec_cpp.txt", ios::trunc | ios::out);
    // fout << out_str.str() << endl;
    // fout << "Secs to complete: " << static_cast<float>(clock() - start)/CLOCKS_PER_SEC << endl;
    // cout << "Secs to complete: " << static_cast<float>(clock() - start)/CLOCKS_PER_SEC << endl;
    // fout.close();
}