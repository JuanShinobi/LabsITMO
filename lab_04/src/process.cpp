#include <iostream>
#include <chrono>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
using namespace chrono;

double f1(double x) {
    return x*x - x*x + x*4 - x*5 + x + x;
}

double f2(double x) {
    return x + x;
}

void run_process(int n) {
    int pipefd[2];
    pipe(pipefd);

    auto start = high_resolution_clock::now();

    pid_t pid = fork();

    if (pid == 0) {
        close(pipefd[0]);
        double r2 = 0;
        for (int i = 0; i < n; i++) r2 += f2(i);
        write(pipefd[1], &r2, sizeof(r2));
        close(pipefd[1]);
        exit(0);
    } else {
        double r1 = 0;
        for (int i = 0; i < n; i++) r1 += f1(i);

        wait(NULL);

        double r2;
        read(pipefd[0], &r2, sizeof(r2));

        double r3 = r1 + r2 - r1;

        auto end = high_resolution_clock::now();

        cout << "PROC (" << n << "): "
             << duration_cast<nanoseconds>(end - start).count()
             << " ns\n";
    }
}

int main() {
    int n1 = 10000;
    int n2 = 100000;
    run_process(n1);
    run_process(n2);
}
