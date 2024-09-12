from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if head is None:
            return None
        
        # If there's only one node, return it as a TreeNode
        if head.next is None:
            return TreeNode(head.val)
        
        # Use two pointers to find the middle of the list
        slow = fast = head
        slow_prev = None
        
        while fast and fast.next:
            slow_prev = slow
            slow = slow.next
            fast = fast.next.next
        
        # slow is the middle node, so it will be the root
        root = TreeNode(slow.val)
        
        # Disconnect the left half from the middle
        if slow_prev:
            slow_prev.next = None
        
        # Recursively build the left and right subtrees
        root.left = self.sortedListToBST(head)  # Left half
        root.right = self.sortedListToBST(slow.next)  # Right half
        
        return root

# Helper function to print the binary tree (for testing purposes)
def preOrder(node):
    if not node:
        return
    print(node.val, end=' ')
    preOrder(node.left)
    preOrder(node.right)

# Helper function to create a linked list from a Python list
def createLinkedList(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

if __name__ == "__main__":
    # Example usage
    lst = [-10, -3, 0, 5, 9]  # A sorted linked list
    head = createLinkedList(lst)
    solution = Solution()
    bst_root = solution.sortedListToBST(head)
    
    print("PreOrder Traversal of the constructed BST:")
    preOrder(bst_root)
