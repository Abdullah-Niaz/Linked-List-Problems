import time

# Definition for singly-linked list


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeNodes(self, head: ListNode) -> ListNode:
        p1 = head.next
        p2 = p1

        while p2 is not None:
            sum_val = 0
            while p2 is not None and p2.val != 0:
                sum_val += p2.val
                p2 = p2.next
            p1.val = sum_val
            p2 = p2.next
            p1.next = p2
            p1 = p1.next

        return head.next

# Helper function to create a linked list from a list of values


def create_list(arr):
    dummy = ListNode(0)
    current = dummy
    for val in arr:
        current.next = ListNode(val)
        current = current.next
    return dummy

# Helper function to print the linked list


def print_list(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()


# Input list to simulate linked list values
arr = [0, 3, 1, 0, 4, 5, 2, 0]  # Example list

head = create_list(arr)

sol = Solution()

# Start measuring time
start_time = time.time()

result = sol.mergeNodes(head)

# Stop measuring time
end_time = time.time()

# Print the result and execution time
print("Merged List: ", end=" ")
print_list(result)

print(f"Execution time: {(end_time - start_time) * 1e6:.2f} microseconds")
