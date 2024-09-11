# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        # Edge case: if the list is empty or has only one node
        if not head or not head.next:
            return None

        slow = fast = head

        # Move slow by 1 step and fast by 2 steps to detect a cycle
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            # If slow and fast meet, there's a cycle
            if slow == fast:
                break

        # If no cycle, return None
        if slow != fast:
            return None

        # Move one pointer to the head, both pointers move one step at a time
        p = head
        while p != slow:
            p = p.next
            slow = slow.next

        # Both pointers meet at the start of the cycle
        return p

# Example Usage
if __name__ == "__main__":
    # Create a linked list with a cycle
    head = ListNode(3)
    node2 = ListNode(2)
    node0 = ListNode(0)
    node_neg4 = ListNode(-4)

    head.next = node2
    node2.next = node0
    node0.next = node_neg4
    node_neg4.next = node2  # Creates a cycle

    solution = Solution()
    result = solution.detectCycle(head)

    if result:
        print(f"Cycle starts at node with value: {result.val}")
    else:
        print("No cycle")
