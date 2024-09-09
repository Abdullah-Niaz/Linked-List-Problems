from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        nums_set = set(nums)  # Convert list to set for O(1) lookup
        
        # Remove nodes from the start of the list that match the set values
        while head and head.val in nums_set:
            head = head.next
        
        # Traverse through the remaining list and remove matching nodes
        curr = head
        while curr and curr.next:
            if curr.next.val in nums_set:
                curr.next = curr.next.next  # Remove node by skipping it
            else:
                curr = curr.next
        
        return head
# Helper function to create a linked list from a list of values
def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

# Helper function to print the linked list
def print_linked_list(head):
    values = []
    while head:
        values.append(head.val)
        head = head.next
    print(" -> ".join(map(str, values)))

# Test the Solution
solution = Solution()
head = create_linked_list([1, 2, 6, 3, 4, 5, 6])
nums = [6]
modified_head = solution.modifiedList(nums, head)

print("Modified Linked List:")
print_linked_list(modified_head)
