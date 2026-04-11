#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

double calc(double x) {
        return x*x -x*x +x*4 - x*5 +x +x;
}

int main() {
        while (true) {
                cout << "Enter iterations: ";
                int n;

                if (!(cin >> n)) {
                        cout << "Invalid input\n";
                        return 0;
                }

                auto start = high_resolution_clock::now();

                for (int i = 0; i < n; i++) {
                        calc(i);
                }

                auto end = high_resolution_clock::now();

                auto duration = duration_cast<milliseconds>(end-start);

                cout << "Time: " << duration.count() << "ms\n";

                cout << "Repeat? (Y/N): ";
                char repeat;
                cin >> repeat;

                if (repeat == 'N') break;
        }

        return 0;
}
