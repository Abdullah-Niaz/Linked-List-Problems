# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        # Create a dummy node to handle cases where the head is part of a zero-sum sequence
        dummy = ListNode(0)
        dummy.next = head

        # Dictionary to store the first occurrence of each prefix sum
        prefix_sum_map = {}

        # First pass to calculate the prefix sums and store the last occurrence of each sum
        prefix_sum = 0
        curr = dummy
        while curr:
            prefix_sum += curr.val
            prefix_sum_map[prefix_sum] = curr
            curr = curr.next

        # Second pass to remove the zero-sum subsequences
        prefix_sum = 0
        curr = dummy
        while curr:
            prefix_sum += curr.val
            # Set the next pointer to skip the nodes that sum to zero
            curr.next = prefix_sum_map[prefix_sum].next
            curr = curr.next

        return dummy.next

# Helper function to create a linked list from a list of values


def create_linked_list(lst):
    dummy = ListNode(0)
    curr = dummy
    for value in lst:
        curr.next = ListNode(value)
        curr = curr.next
    return dummy.next

# Helper function to print the linked list


def print_linked_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    print(result)


# Test the solution
if __name__ == "__main__":
    # Test case: input list
    input_list = [1, 2, -3, 3, 1]

    # Create linked list from input
    head = create_linked_list(input_list)

    # Create solution instance
    sol = Solution()

    # Remove zero sum sublists
    result_head = sol.removeZeroSumSublists(head)

    # Print the result
    print_linked_list(result_head)
