import random

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:

    def __init__(self, head):
        self.arr = []  # Store the values of the linked list in an instance variable
        temp = head
        while temp:
            self.arr.append(temp.val)  # Append the value of each node to the array
            temp = temp.next

    def getRandom(self) -> int:
        # Select and return a random element from the array
        return random.choice(self.arr)


# Main function to create a linked list and test the Solution class
def main():
    # Creating a simple linked list: 1 -> 2 -> 3
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    
    # Instantiate the solution with the linked list head
    solution = Solution(head)
    
    # Get a random node's value
    print("Random node value:", solution.getRandom())

if __name__ == "__main__":
    main()
