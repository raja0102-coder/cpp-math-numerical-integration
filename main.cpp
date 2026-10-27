#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Example function to integrate: f(x) = 1 / (1 + x^2)
double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// 1. Trapezoidal Rule
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// 2. Simpson's 1/3 Rule (n must be even)
double simpsonsOneThirdRule(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "    [WARNING] n must be even for Simpson's 1/3 Rule. Adjusting n to " << (n + 1) << "\n";
        n++;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2.0 * f(x);
        } else {
            sum += 4.0 * f(x);
        }
    }
    return sum * (h / 3.0);
}

int main() {
    cout << "==================================================\n";
    cout << "    SEM 2 MATH: NUMERICAL INTEGRATION ENGINE      \n";
    cout << "==================================================\n\n";

    double a = 0.0; // Lower limit
    double b = 1.0; // Upper limit
    int n = 6;      // Number of subintervals

    cout << fixed << setprecision(6);
    cout << "    Function: f(x) = 1 / (1 + x^2)\n";
    cout << "    Limits  : [" << a << ", " << b << "]\n";
    cout << "    Intervals (n): " << n << "\n\n";

    // 1. Trapezoidal Calculation
    double trapResult = trapezoidalRule(a, b, n);
    cout << "[1] TRAPEZOIDAL RULE RESULT:\n";
    cout << "    Approximated Integral = " << trapResult << "\n\n";

    // 2. Simpson's 1/3 Calculation
    double simpResult = simpsonsOneThirdRule(a, b, n);
    cout << "[2] SIMPSON'S 1/3 RULE RESULT:\n";
    cout << "    Approximated Integral = " << simpResult << "\n\n";

    cout << "==================================================\n";

    return 0;
}
