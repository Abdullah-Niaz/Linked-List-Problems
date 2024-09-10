# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        # Initialize pointers for odd and even lists
        odd = head
        even = head.next
        evenHead = even

        # Rearrange nodes
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        # Connect the end of the odd list to the head of the even list
        odd.next = evenHead

        return head

# Helper function to create a linked list from a list


def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for value in arr[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

# Helper function to print the linked list


def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "\n")
        current = current.next


# Example usage
if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]  # Sample input
    head = create_linked_list(arr)

    # Apply the oddEvenList transformation
    solution = Solution()
    new_head = solution.oddEvenList(head)

    # Print the result
    print_linked_list(new_head)
