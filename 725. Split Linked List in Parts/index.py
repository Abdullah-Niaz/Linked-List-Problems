# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def splitListToParts(self, head: ListNode, k: int):
        # Find the length of the linked list
        curr = head
        L = 0
        while curr:
            L += 1
            curr = curr.next
        
        # Calculate the number of nodes in each part and the remainder
        eachBucketNodes = L // k
        remainderNodes = L % k
        
        result = [None] * k  # Initialize result list with k None elements
        curr = head
        
        for i in range(k):
            result[i] = curr  # Start of the current part
            
            # Calculate the size of the current part
            partSize = eachBucketNodes + (1 if remainderNodes > 0 else 0)
            
            # Traverse the nodes for the current part
            for _ in range(partSize - 1):
                if curr:
                    curr = curr.next
            
            # Move to the next part and break the link
            if curr:
                nextPart = curr.next
                curr.next = None  # Break the link for the current part
                curr = nextPart  # Move to the start of the next part
            
            remainderNodes -= 1  # Decrement remainder as extra nodes are handled
        
        return result

# Helper function to print the linked list parts
def printParts(parts):
    for i, part in enumerate(parts):
        print(f"Part {i + 1}: ", end="")
        curr = part
        while curr:
            print(curr.val, end=" ")
            curr = curr.next
        print()

# Helper function to create a linked list from a list of values
def createList(values):
    if not values:
        return None
    head = ListNode(values[0])
    curr = head
    for val in values[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

if __name__ == "__main__":
    # Create a sample linked list
    values = [1, 2, 3, 4, 5]
    head = createList(values)
    k = 3

    # Split the linked list into parts
    solution = Solution()
    parts = solution.splitListToParts(head, k)

    # Print the split parts
    printParts(parts)
