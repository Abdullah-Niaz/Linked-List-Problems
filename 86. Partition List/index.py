# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # Create two new lists: one for nodes < x, and another for nodes >= x
        small = ListNode(0)
        large = ListNode(0)

        # Pointers to track the current nodes in each list
        smallP = small
        largeP = large

        # Traverse the original list
        while head:
            if head.val < x:
                smallP.next = head
                smallP = smallP.next
            else:
                largeP.next = head
                largeP = largeP.next

            # Move to the next node
            head = head.next

        # Connect the small list to the large list
        smallP.next = large.next
        # End the large list
        largeP.next = None

        # Return the partitioned list, starting with small list's head
        return small.next

# Helper function to create a linked list from a list of values


def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Helper function to print the linked list


def print_linked_list(head):
    while head:
        print(f"{head.val} -> ", end="")
        head = head.next
    print("None")


if __name__ == "__main__":
    solution = Solution()

    # Test case: [1, 4, 3, 2, 5, 2], partition around x = 3
    head = create_linked_list([1, 4, 3, 2, 5, 2])

    print("Original List: ")
    print_linked_list(head)

    # Partition the list with x = 3
    head = solution.partition(head, 3)

    print("Partitioned List: ")
    print_linked_list(head)
