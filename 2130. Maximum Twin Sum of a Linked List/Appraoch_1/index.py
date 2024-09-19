# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Function to add a node at the end of the list


def append_node(head, val):
    if not head:
        return ListNode(val)
    current = head
    while current.next:
        current = current.next
    current.next = ListNode(val)
    return head


class Solution:
    def pairSum(self, head: ListNode) -> int:
        values = []
        current = head
        while current:
            values.append(current.val)
            current = current.next

        result = 0
        i, j = 0, len(values) - 1
        while i < j:
            result = max(result, values[i] + values[j])
            i += 1
            j -= 1

        return result


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
