import math

# Constants
C = 0.826991  # Approximation of the binary Champernowne constant (A066716)

# Define r(x) as per the formula
def r(x):
    return 2 ** (x - 1 + 2 ** (1 - x))

# Define frac(x) to compute the fractional part of x
def frac(x):
    return x - math.floor(x)

# Compute a(n) based on the given formula
def a(n):
    if n <= 0:
        raise ValueError("n must be a positive integer")
    
    log2_n = math.log2(n)
    fractional_part = frac(log2_n)
    r_value = r(fractional_part)
    
    term1 = 4 * C / (2 ** fractional_part)
    term2 = n ** (n + 1)
    term3 = r_value ** n
    
    result = term1 * term2 / term3
    return math.floor(result)

# Example usage
n = int(input())
print(f"a({n}) = {a(n)}")
