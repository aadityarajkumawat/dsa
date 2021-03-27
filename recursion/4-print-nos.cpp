#include <iostream>

void dec(int n)
{
    if (n == 0)
        return;

    std::cout << n << std::endl;
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
        return;
    inc(n - 1);
    std::cout << n << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << std::endl;
    dec(n);
    std::cout << std::endl;
    inc(n);
    return 0;
}