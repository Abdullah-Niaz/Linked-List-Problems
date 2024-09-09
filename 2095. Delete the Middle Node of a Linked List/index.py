from typing import Optional

# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # If the list is empty or has only one node, return None
        if not head or not head.next:
            return None

        # Initialize slow pointer to the head
        slow = head
        # Initialize fast pointer to two nodes ahead
        fast = head.next

        # Traverse the list with slow and fast pointers
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Slow pointer is now at the node just before the middle node
        # Delete the middle node
        middle = slow.next
        slow.next = slow.next.next

        # Return the modified list head
        return head

# Helper function to print the linked list


def print_list(head: Optional[ListNode]):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

# Helper function to create a linked list from a list of values


def create_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head


# Main function to test the deleteMiddle function
if __name__ == "__main__":
    # Test case: Linked list [1, 2, 3, 4, 5]
    values = [1, 2, 3, 4, 5]
    head = create_list(values)
    print("Original list: ", end="")
    print_list(head)

    solution = Solution()
    head = solution.deleteMiddle(head)
    print("After deleting middle: ", end="")
    print_list(head)
