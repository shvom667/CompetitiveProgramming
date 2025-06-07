import heapq
import random

def huffman_best_len(nums, deno):
    """
    Calculates the average code length of an optimal Huffman code.

    Args:
        nums: A list of integers representing the frequencies (or counts)
              of symbols.
        deno: A list where each element is the total sum of frequencies
              (denominator for calculating probabilities, though only the
              total sum is needed). Assumed deno[0] == sum(nums).

    Returns:
        The average code length (float) achieved by the Huffman code
        for the given frequencies. Returns 0.0 if there are 0 or 1 symbols,
        or if the total frequency is 0.
    """

    # Handle edge cases: no symbols or only one symbol
    if not nums or len(nums) <= 1:
        return 0.0

    # Calculate total frequency. Using sum(nums) is robust.
    # Using deno[0] assumes deno is correctly populated as per the example.
    total_frequency = sum(nums)
    # Alternative: total_frequency = deno[0]

    # Handle edge case: total frequency is zero (e.g., nums = [0, 0])
    if total_frequency == 0:
        return 0.0

    # Use a min-heap (priority queue) to efficiently find the lowest frequencies.
    # Initialize the heap with the frequencies.
    # We don't need to store the symbols themselves, just their frequencies,
    # to calculate the average length using the weighted path length method.
    heap = list(nums) # Create a mutable copy
    heapq.heapify(heap) # Convert the list into a min-heap in-place

    # Variable to accumulate the total weighted path length.
    # Each merge step adds the combined frequency to this sum.
    total_weighted_path_length = 0

    # Huffman algorithm: repeatedly merge the two lowest frequency nodes
    while len(heap) > 1:
        # Extract the two nodes with the smallest frequencies
        freq1 = heapq.heappop(heap)
        freq2 = heapq.heappop(heap)

        # Create a new internal node with the combined frequency
        combined_freq = freq1 + freq2

        # The combined frequency represents the sum of frequencies of all
        # leaf nodes (original symbols) in the subtree rooted at this new
        # internal node. Each of these symbols is now one level deeper
        # in the tree due to this merge. Adding the combined_freq to
        # the total weighted path length accounts for this increase in depth
        # for all affected symbols simultaneously.
        # Sum(frequency * length) increases by Sum(frequency * 1) = combined_freq
        total_weighted_path_length += combined_freq

        # Add the new internal node (represented by its frequency) back to the heap
        heapq.heappush(heap, combined_freq)

    # The average code length is the total weighted path length divided
    # by the total frequency of all symbols.
    average_length = total_weighted_path_length / total_frequency

    return average_length

class Node:
    def __init__(self, value  = 0):
        self.value = value
        self.leftChild = None
        self.rightChild = None
    def __lt__(self, other):
        return self.value < other.value

    def __add__(self, other):
        assert(isinstance(other, Node))
        return Node(self.value + other.value)
    def __print__(self):
        print(self.value)
    def dfs_print(self, level=0, prefix=""):
        indent = "    " * level
        print(f"{indent}{prefix}{self.value}")

        if self.leftChild:
            self.leftChild.dfs_print(level + 1, "L: ")
        if self.rightChild:
            self.rightChild.dfs_print(level + 1, "R: ")

            

def optimal_length(root, length = 0):
    ans = 0
    if root.leftChild is None and root.rightChild is None:
        return root.value * length
    ans += optimal_length(root.leftChild, length+1)
    ans += optimal_length(root.rightChild, length+1)
    return ans



def dfs(root: Node):

    if root.leftChild is None:
        return
    if root.rightChild is None:
        return

    print(root.value)
    dfs(root.leftChild)
    dfs(root.rightChild)


def my_huffman(nums, deno):
    n = []
    for value in nums:
        n.append(Node(value))


    print(n)
    heapq.heapify(n)
    
    while len(n) > 1:


        n1 = heapq.heappop(n)
        n2 = heapq.heappop(n)

        n3 = n1 + n2


        n3.leftChild = n1
        n3.rightChild = n2

        heapq.heappush(n, n3)

    

    n[0].dfs_print()


    res = optimal_length(n[0])
    


    return res / sum(nums)



if __name__ == "__main__":
    #nums = [1, 2, 3, 4, 4]

    while True:
        nums = [random.randint(1, 100) for _ in range(10)]
        total_sum = sum(nums)
        deno = [sum(nums)] * len(nums)


        my = my_huffman(nums, deno)

        res = huffman_best_len(nums,deno)
        print(my, res)
        assert(res == my)




# OK, No huffman has nothing to do with such a prefix difference array 