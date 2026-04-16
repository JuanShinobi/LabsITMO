#include <iostream>
#include <string>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double power(double a, int b) {
    double result = 1;
    for (int i = 0; i < b; i++) {
        result = result * a;
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: calc [plus|minus|power] a b\n";
        return 1;
    }

    string op = argv[1];
    double a = stod(argv[2]);
    double b = stod(argv[3]);

    if (op == "plus") {
        cout << add(a, b) << endl;
    } else if (op == "minus") {
        cout << sub(a, b) << endl;
    } else if (op == "power") {
        cout << power(a, (int)b) << endl;
    } else {
        cout << "Unknown operation\n";
    }

    return 0;
}
