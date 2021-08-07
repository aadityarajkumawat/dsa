// O(2^n) time | O(n) space
function nThFibonacci(n) {
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else return nThFibonacci(n - 1) + nThFibonacci(n - 2);
}

console.log(nThFibonacci(8));
