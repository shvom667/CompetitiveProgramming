def maximize_ratio(tuples):
    # Initialize sum of numerators and denominators
    total_numerator = 0
    total_denominator = 0
    
    # Process each tuple
    for numerator1, denominator1, numerator2, denominator2 in tuples:
        # Calculate the two possible choices
        ratio1 = numerator1 / denominator1
        ratio2 = numerator2 / denominator2
        
        # Choose the option that maximizes the ratio
        if ratio1 > ratio2:
            total_numerator += numerator1
            total_denominator += denominator1
        else:
            total_numerator += numerator2
            total_denominator += denominator2
    
    # Return the final ratio
    if total_denominator == 0:  # To avoid division by zero
        return 0
    return total_numerator / total_denominator

# Function to take input from the user
def take_input():
    n = int(input("Enter the number of tuples: "))
    tuples = []
    
    for _ in range(n):
        denominator1, numerator1, denominator2, numerator2 = map(int, input().split())
        tuples.append((numerator1, denominator1, numerator2, denominator2))
    
    return tuples

# Main function
def main():
    tuples = take_input()  # Take the input from the user
    result = maximize_ratio(tuples)  # Calculate the maximum ratio
    print(f"Maximum Ratio: {result}")

# Run the program
main()

