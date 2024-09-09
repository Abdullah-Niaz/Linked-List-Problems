# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # Check if node or next node is None
        if node is None or node.next is None:
            raise Exception("Cannot delete this node.")
        
        # Overwrite the value of the current node with the value of the next node
        node.val = node.next.val
        
        # Bypass the next node
        node.next = node.next.next

# Helper function to print the linked list
def printList(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

# Example usage
if __name__ == "__main__":
    # Creating a linked list: 4 -> 5 -> 1 -> 9 -> None
    head = ListNode(4)
    head.next = ListNode(5)
    head.next.next = ListNode(1)
    head.next.next.next = ListNode(9)
    
    # Print the original list
    print("Original list:")
    printList(head)
    
    # Deleting node with value 5
    Solution().deleteNode(head.next)
    
    # Print the modified list
    print("List after deleting node 5:")
    printList(head)
