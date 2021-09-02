// Recursive function to return the factorial of a number
int factorial(int n) {
    return (n == 1) ? 1 : n * factorial(n - 1);
}