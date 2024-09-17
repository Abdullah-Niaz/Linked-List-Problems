# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        temp = head.next
        head.next = self.swapPairs(head.next.next)
        temp.next = head
        return temp

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

    # Test case: [1, 2, 3, 4]
    head = create_linked_list([1, 2, 3, 4])

    print("Original List: ")
    print_linked_list(head)

    head = solution.swapPairs(head)

    print("Swapped List: ")
    print_linked_list(head)
