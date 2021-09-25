#include <iostream>
using namespace std;
// this is added
int calc_factorial(int x) {
    int factorial;
    if (x == 1) return x;
    return x * calc_factorial(x - 1);
}

int main() {
    int numbers;
    cin >> numbers;
    for (int i = 0; i < numbers; i++) {
        int x;
        cin >> x;
        int factorial = calc_factorial(x);
        int number_of_zeros = 0;
        while (factorial % 10 == 0) {
            number_of_zeros++;
            factorial = factorial / 10;
        }
        cout << number_of_zeros;
        cout << endl;
    }
    return 0;
}
