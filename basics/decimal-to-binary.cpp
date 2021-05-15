#include <iostream>
using namespace std;

void decimal_to_binary(int n) {
    int reversed_num = 0;
    int final_num = 0;

    while (n != 0) {
        reversed_num = reversed_num * 10 + n % 2;
        n = n / 2;
    }

    while (reversed_num != 0) {
        final_num = final_num * 10 + reversed_num % 10;
        reversed_num = reversed_num / 10;
    }

    cout << final_num << endl;
}

int main() {
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    decimal_to_binary(n);

    return 0;
}
