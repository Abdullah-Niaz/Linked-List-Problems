class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseLL(self, head):
        if not head or not head.next:
            return head

        last = self.reverseLL(head.next)
        head.next.next = head
        head.next = None
        return last

    def addTwoNumbers(self, l1, l2):
        l1 = self.reverseLL(l1)
        l2 = self.reverseLL(l2)
        sum = 0
        carry = 0
        ans = ListNode()

        current = ans

        while l1 or l2:
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next

            current.val = sum % 10
            carry = sum // 10
            new_node = ListNode(carry)
            new_node.next = current
            current = new_node
            sum = carry

        return current.next if carry == 0 else current

# Helper functions to create and print a linked list.


def create_list(values):
    head = ListNode()
    current = head
    for value in values:
        current.next = ListNode(value)
        current = current.next
    return head.next


def print_list(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()


if __name__ == "__main__":
    solution = Solution()

    # Create two linked lists
    l1 = create_list([7, 2, 4, 3])
    l2 = create_list([5, 6, 4])

    # Add the two numbers
    result = solution.addTwoNumbers(l1, l2)

    # Print the result
    print_list(result)
