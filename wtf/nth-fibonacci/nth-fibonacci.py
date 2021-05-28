# O(2^n) time | O(n) space
def nThFibonacci(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return nThFibonacci(n - 1) + nThFibonacci(n - 2)


print(nThFibonacci(5))
