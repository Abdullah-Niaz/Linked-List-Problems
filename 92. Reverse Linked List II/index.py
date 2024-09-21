# Definition for singly-linked list node.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        # Edge cases: if the list is empty or has only one node.
        if not head or not head.next:
            return head

        # Create a dummy node to simplify the reversal process.
        dummy = ListNode(0)
        dummy.next = head

        # prev points to the node just before the 'left' position.
        prev = dummy
        for i in range(left - 1):
            prev = prev.next

        # curr is the node at the 'left' position.
        curr = prev.next

        # Reverse the sublist from 'left' to 'right'.
        for i in range(right - left):
            temp = prev.next
            prev.next = curr.next
            curr.next = curr.next.next
            prev.next.next = temp

        # Return the new head of the list (dummy.next).
        return dummy.next

# Helper function to print the linked list


def print_list(node):
    while node:
        print(node.val, end=" -> " if node.next else "\n")
        node = node.next

# Helper function to create a linked list from a list of values


def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    curr = head
    for val in values[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head


# Main function to execute in VSCode
if __name__ == "__main__":
    # Example: reverse the sublist from position 2 to 4 in the linked list [1, 2, 3, 4, 5]
    values = [1, 2, 3, 4, 5]
    head = create_linked_list(values)

    print("Original List:")
    print_list(head)

    solution = Solution()
    new_head = solution.reverseBetween(head, 2, 4)

    print("\nReversed Sublist (from position 2 to 4):")
    print_list(new_head)
