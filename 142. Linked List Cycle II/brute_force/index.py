class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        # Brute Force
        visited = set()  # HashSet to store visited nodes
        current = head

        # Traverse the list
        while current:
            if current in visited:  # If the node is already visited, cycle is found
                return current
            visited.add(current)  # Add current node to visited set
            current = current.next  # Move to the next node

        return None  # No cycle found


# You can use this code in your local VS Code environment.
# Example usage:
head = ListNode(3)
node2 = ListNode(2)
node0 = ListNode(0)
node_neg4 = ListNode(-4)
head.next = node2
node2.next = node0
node0.next = node_neg4
node_neg4.next = node2  # Creates a cycle


sol = Solution()
result = sol.detectCycle(head)
print(result.val if result else "No cycle")  # It should print 2
