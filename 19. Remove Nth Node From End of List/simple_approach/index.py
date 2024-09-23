class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def travel_front(self, head: ListNode) -> int:
        length = 0
        while head:
            length += 1
            head = head.next
        return length

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        L = self.travel_front(head)  # Get the total length of the list

        # If we need to remove the first node (nth node from end is the head)
        if n == L:
            return head.next

        steps = L - n  # Calculate how many nodes to skip to get to the node before the one to remove
        temp = head
        prev = None

        while steps > 0:  # Move 'steps' forward
            prev = temp
            temp = temp.next
            steps -= 1

        # Now 'temp' points to the nth node from the end, and 'prev' is the node before it
        prev.next = temp.next  # Remove the nth node
        return head

# Utility function to print the linked list


def printList(node):
    while node:
        print(node.val, end=" ")
        node = node.next
    print()

# Helper function to create a list from array


def createList(arr):
    head = ListNode(arr[0])
    curr = head
    for i in range(1, len(arr)):
        curr.next = ListNode(arr[i])
        curr = curr.next
    return head


# Example usage
if __name__ == "__main__":
    solution = Solution()

    arr = [1, 2, 3, 4, 5]
    n = 2
    head = createList(arr)

    print("Original List:", end=" ")
    printList(head)

    head = solution.removeNthFromEnd(head, n)

    print("Modified List:", end=" ")
    printList(head)
