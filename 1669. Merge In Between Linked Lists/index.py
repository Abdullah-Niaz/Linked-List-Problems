# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        left = right = list1

        # Traverse to find left (node at a-1) and right (node at b+1)
        for i in range(b + 1):
            if i == a - 1:
                left = right
            right = right.next

        # Connect left's next to the head of list2
        left.next = list2

        # Traverse to the end of list2
        temp = list2
        while temp.next is not None:
            temp = temp.next

        # Connect the end of list2 to right (node after b)
        temp.next = right

        return list1

# Helper function to print the linked list


def print_linked_list(head: ListNode):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "\n")
        current = current.next

# Helper function to create a linked list from a list


def create_linked_list(lst):
    dummy = ListNode()
    current = dummy
    for val in lst:
        current.next = ListNode(val)
        current = current.next
    return dummy.next


# Testing the solution
if __name__ == "__main__":
    # Create list1 and list2
    list1 = create_linked_list([0, 1, 2, 3, 4, 5, 6])
    list2 = create_linked_list([1000000, 1000001, 1000002, 1000003, 1000004])

    # Set a and b
    a, b = 2, 5

    # Instantiate Solution and merge the lists
    solution = Solution()
    result = solution.mergeInBetween(list1, a, b, list2)

    # Print the result
    print("Merged linked list:")
    print_linked_list(result)
