def execute_program(registers, program):
    A, B, C = registers['A'], registers['B'], registers['C']
    output = []
    
    def get_combo_value(operand):
        if operand == 0: return 0
        elif operand == 1: return 1
        elif operand == 2: return 2
        elif operand == 3: return 3
        elif operand == 4: return A
        elif operand == 5: return B
        elif operand == 6: return C
        else: raise ValueError("Invalid combo operand")
    
    ip = 0
    program_len = len(program)
    
    while ip < program_len:
        opcode = program[ip]
        operand = program[ip + 1] if ip + 1 < program_len else 0
        
        if opcode == 0:  # adv
            denom = 2 ** get_combo_value(operand)
            A //= denom
        
        elif opcode == 1:  # bxl
            B ^= operand
        
        elif opcode == 2:  # bst
            B = get_combo_value(operand) % 8
        
        elif opcode == 3:  # jnz
            if A != 0:
                ip = operand
                continue
        
        elif opcode == 4:  # bxc
            B ^= C
        
        elif opcode == 5:  # out
            output.append(get_combo_value(operand) % 8)
        
        elif opcode == 6:  # bdv
            denom = 2 ** get_combo_value(operand)
            B = A // denom
        
        elif opcode == 7:  # cdv
            denom = 2 ** get_combo_value(operand)
            C = A // denom
        
        else:
            raise ValueError("Invalid opcode")
        
        ip += 2
    
    return output

def find_initial_A(program):
    target_output = program[:]  # The program itself is the target output
    
    A = 1  # Start testing from the lowest positive integer
    while True:
        registers = {'A': A, 'B': 0, 'C': 0}
        output = execute_program(registers, program)

        print(A, output==target_output)
        
        if output == target_output:
            print(A)
        
        A += 1

# Input program
program = [2,4,1,2,7,5,4,3,0,3,1,7,5,5,3,0]
program = [0, 3, 5, 4, 3, 0]

# Find the lowest initial value of register A
result = find_initial_A(program)
print("The lowest value of A that causes the program to output itself is:", result)

