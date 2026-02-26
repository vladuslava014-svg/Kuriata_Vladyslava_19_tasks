#include <iostream>
#include <cmath>
using namespace std;


long long factorial(int n) {
    if (n < 0) return 0; 
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
   
    int m = 4, n = 4;

    long long part1_top = factorial(2 * m);
    long long part1_bottom = factorial(2 * m - n);
    double part1 = (double)part1_top / part1_bottom;

    long long part2_top = factorial(5 * m - 2 * n);
    long long part2_bottom = factorial(n + m);
    double part2 = (double)part2_top / part2_bottom;

    double A = sqrt(part1) + 3 * pow(part2, 1.0 / 3.0);

    cout << "Calculation results for m = " << m << ", n = " << n << ":" << endl;
    cout << "A = " << A << endl;

    return 0;
}