# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)  # Create a dummy node to handle edge cases
        dummy.next = head
        lead_ptr = dummy
        trail_ptr = dummy

        # Move lead_ptr n steps ahead
        for _ in range(n):
            lead_ptr = lead_ptr.next

        # Move both pointers until lead_ptr reaches the end
        while lead_ptr.next:
            lead_ptr = lead_ptr.next
            trail_ptr = trail_ptr.next

        # trail_ptr is now just before the node to be removed
        delete_node = trail_ptr.next
        trail_ptr.next = trail_ptr.next.next  # Skip the node to remove

        # Delete the node (Python handles garbage collection automatically)
        return dummy.next  # Return the new head of the list

# Utility function to create a linked list from a list of values


def create_linked_list(arr):
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Utility function to print the linked list


def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()


# Example usage:
arr = [1, 2, 3, 4, 5]
n = 2
solution = Solution()

head = create_linked_list(arr)
print("Original Linked List:")
print_linked_list(head)

# Remove the nth node from the end
new_head = solution.removeNthFromEnd(head, n)

print("Modified Linked List:")
print_linked_list(new_head)
