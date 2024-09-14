import heapq

# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Function to merge k sorted linked lists


def mergeKLists(lists):
    if not lists or len(lists) == 0:
        return None

    # Define a min-heap to store (node value, list index, node)
    min_heap = []

    # Initialize the heap with the head of each list
    for i in range(len(lists)):
        if lists[i]:
            heapq.heappush(min_heap, (lists[i].val, i, lists[i]))

    # Dummy node to form the merged list
    dummy = ListNode()
    current = dummy

    # Process the heap until it's empty
    while min_heap:
        # Extract the smallest node
        val, idx, node = heapq.heappop(min_heap)

        # Append the node to the result list
        current.next = node
        current = current.next

        # If the extracted node has a next node, push it into the heap
        if node.next:
            heapq.heappush(min_heap, (node.next.val, idx, node.next))

    return dummy.next

# Helper function to convert a Python list to a linked list


def build_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Helper function to convert a linked list to a Python list (for easy comparison)


def linked_list_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result


# Main function to test the code
if __name__ == "__main__":
    # Example input: lists = [[1,4,5],[1,3,4],[2,6]]
    lists = [
        build_linked_list([1, 4, 5]),
        build_linked_list([1, 3, 4]),
        build_linked_list([2, 6])
    ]

    # Merge the k sorted linked lists
    merged_list_head = mergeKLists(lists)

    # Convert the result linked list back to a Python list and print it
    result = linked_list_to_list(merged_list_head)
    print(result)
