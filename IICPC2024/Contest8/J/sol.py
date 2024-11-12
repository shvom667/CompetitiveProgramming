def solve():
    n = int(input())  # number of species
    species = []

    # Read species information
    for _ in range(n):
        ai, bi = map(int, input().split())
        species.append((ai, bi))
    
    # Sort species by b_i in ascending order (for easier processing)
    species.sort(key=lambda x: x[1])

    # Variables to track the last day and total number of birds that will fly away
    total_birds_left = sum(ai for ai, bi in species)
    last_day = 0
    total_birds_departed = 0

    for ai, bi in species:
        # Birds will leave on the next day after those with bi or more are already gone
        last_day += 1
        # The number of birds leaving is all the birds of the current species
        total_birds_departed += ai
        # Subtract the number of birds left in the valley
        total_birds_left -= ai
    
    # Output the result
    print(last_day, total_birds_departed)

solve()
