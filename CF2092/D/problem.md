D. Mishkin Energizer

Time Limit: 2 seconds

Memory Limit: 256 megabytes

Input: standard input

Output: standard output

In anticipation of a duel with his old friend Fernan, Edmond is preparing an energy drink called "Mishkin Energizer". The drink consists of a string s of length n, made up only of the characters L, I, and T, which correspond to the content of three different substances in the drink.

We call the drink balanced if it contains an equal number of all substances. To boost his aura and ensure victory in the duel, Edmond must make the initial string balanced by applying the following operation:

Choose an index i such that s<sub>i</sub> ≠ s<sub>i+1</sub> (where i + 1 must not exceed the current size of the string).

Insert a character x, either L, I, or T, between them such that x ≠ s<sub>i</sub> and x ≠ s<sub>i+1</sub>.

Help Edmond make the drink balanced and win the duel by performing no more than 2n operations. If there are multiple solutions, any one of them can be output. If it is impossible, you must report this.

Input

Each test consists of several test cases. The first line of the input data contains one integer t (1 ≤ t ≤ 100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer n (1 ≤ n ≤ 100) — the length of the string s.

The second line of each test case contains a string s of length n, consisting only of the characters L, I, and T.

Output

For each test case, output -1 if there is no solution. Otherwise, in the first line, output a single integer m (0 ≤ m ≤ 2n) — the number of operations you performed.

Then the l-th of the following m lines should contain a single integer i (1 ≤ i < n + l - 1), indicating the operation of inserting a character between s<sub>i</sub> and s<sub>i+1</sub>. It must hold that s<sub>i</sub> ≠ s<sub>i+1</sub>.

If there are multiple solutions, any one of them can be output. Note that you do not need to minimize the number of operations in this problem.

Example
Input:
3
5
TILII
1
L
3
LIT

Output:
4
1
2
3
4
-1
0

Note

In the first test case, the following sequence of operations can be performed: TILII → TLILII → TLTILII → TLTLILII → TLTLTILII.

In the second test case, no operations can be performed, so the answer is -1.

In the third test case, the initial string already has equal quantities of all substances.
