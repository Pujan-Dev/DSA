import math

def fibonacci(n):
    phi = (1 + math.sqrt(5)) / 2
    psi = (1 - math.sqrt(5)) / 2
    
    fib_n = (phi**n - psi**n) / math.sqrt(5)
    return round(fib_n)

if __name__ == "__main__":
    n = 400
    print(f"Fibonacci({n}) = {fibonacci(n)}")

