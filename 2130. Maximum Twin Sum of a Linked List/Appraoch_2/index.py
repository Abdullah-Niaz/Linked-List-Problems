# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def pairSum(self, head: ListNode) -> int:
        # Step 1: Use a stack to store the node values
        stack = []
        curr = head
        while curr:
            stack.append(curr.val)
            curr = curr.next

        # Step 2: Find the maximum pair sum
        N = len(stack)
        curr = head
        count = 1
        result = 0
        while count <= N // 2:
            result = max(result, curr.val + stack.pop())
            curr = curr.next
            count += 1

        return result

# Helper function to add nodes to the linked list


def append_node(head, val):
    if not head:
        return ListNode(val)
    current = head
    while current.next:
        current = current.next
    current.next = ListNode(val)
    return head


if __name__ == "__main__":
    head = None
    sol = Solution()

    # Sample input
    nodes = [4, 2, 6, 1]
    for val in nodes:
        head = append_node(head, val)

    # Calculate and print the result
    result = sol.pairSum(head)
    print("Maximum pair sum:", result)
