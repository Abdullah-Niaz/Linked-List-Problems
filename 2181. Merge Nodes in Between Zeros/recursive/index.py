# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeNodes(self, head: ListNode) -> ListNode:
        # Move the head to the first non-zero node
        head = head.next

        if head is None:
            return head

        # Initialize temp to traverse and sum to accumulate values
        temp = head
        sum_val = 0

        # Traverse until the next zero node or the end of the list
        while temp is not None and temp.val != 0:
            sum_val += temp.val
            temp = temp.next

        # Set the head's value to the sum of the non-zero nodes
        head.val = sum_val

        # Recursively call mergeNodes for the remaining list starting from the next zero node
        head.next = self.mergeNodes(temp)

        return head

# Helper function to create a linked list from a list of values
def create_list(arr):
    dummy = ListNode(0)
    current = dummy
    for val in arr:
        current.next = ListNode(val)
        current = current.next
    return dummy

# Helper function to print the linked list
def print_list(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

# Example usage
arr = [0, 3, 1, 0, 4, 5, 2, 0]  # Example input list

# Create the list and call the solution
head = create_list(arr)
sol = Solution()
result = sol.mergeNodes(head)

# Print the merged list
print("Merged List: ", end=" ")
print_list(result)
