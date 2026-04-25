#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

double f1(double x) {
    return x*x - x*x + x*4 - x*5 + x + x;
}

double f2(double x) {
    return x + x;
}

void calc_f1(int n, double& res) {
    for (int i = 0; i < n; i++) res += f1(i);
}

void calc_f2(int n, double& res) {
    for (int i = 0; i < n; i++) res += f2(i);
}

void run_threads(int n) {
    double r1 = 0, r2 = 0;

    auto start = high_resolution_clock::now();

    thread t1(calc_f1, n, ref(r1));
    thread t2(calc_f2, n, ref(r2));

    t1.join();
    t2.join();

    double r3 = r1 + r2 - r1;

    auto end = high_resolution_clock::now();

    cout << "THREAD (" << n << "): "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n";
}

int main() {
    int n1 = 10000;
    int n2 = 100000;
    run_threads(n1);
    run_threads(n2);
}
