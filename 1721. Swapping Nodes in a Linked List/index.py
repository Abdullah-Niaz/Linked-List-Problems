# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def findLength(self, head: ListNode) -> int:
        l = 0
        while head:
            l += 1
            head = head.next
        return l

    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        L = self.findLength(head)

        # Find the k-th node from the start
        Node1 = head
        for _ in range(k - 1):
            Node1 = Node1.next

        # Find the k-th node from the end
        Node2 = head
        for _ in range(L - k):
            Node2 = Node2.next

        # Swap the values of Node1 and Node2
        Node1.val, Node2.val = Node2.val, Node1.val

        return head

# Utility function to print the linked list


def printList(head: ListNode):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

# Utility function to create a linked list from a list


def createList(arr):
    head = ListNode(arr[0])
    temp = head
    for i in range(1, len(arr)):
        temp.next = ListNode(arr[i])
        temp = temp.next
    return head


if __name__ == "__main__":
    solution = Solution()

    # Example list: 1 -> 2 -> 3 -> 4 -> 5
    arr = [1, 2, 3, 4, 5]
    head = createList(arr)
    print("Original List:", end=" ")
    printList(head)

    k = 2  # Example input k
    head = solution.swapNodes(head, k)

    print("List after swapping:", end=" ")
    printList(head)
