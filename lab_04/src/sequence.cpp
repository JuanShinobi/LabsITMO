#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

double f1(double x) {
    return x*x - x*x + x*4 - x*5 + x + x;
}

double f2(double x) {
    return x + x;
}

void run_sequence(int n) {
    auto start = high_resolution_clock::now();

    double r1 = 0, r2 = 0;

    for (int i = 0; i < n; i++) {
        r1 += f1(i);
    }

    for (int i = 0; i < n; i++) {
        r2 += f2(i);
    }

    double r3 = r1 + r2 - r1;

    auto end = high_resolution_clock::now();

    cout << "SEQ (" << n << "): "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n";
}

int main() {
    int n1 = 10000;
    int n2 = 100000;

    run_sequence(n1);
    run_sequence(n2);
}
