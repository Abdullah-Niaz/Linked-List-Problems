class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def reverse_linked_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next   # Step 1
        current.next = prev        # Step 2
        prev = current             # Step 3
        current = next_node        # Step 3

    return prev  # New head

# Helper to print list


def print_list(head):
    temp = head
    while temp:
        print(temp.data, end=" → ")
        temp = temp.next
    print("NULL")


# Example
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

print("Original List:")
print_list(head)

head = reverse_linked_list(head)

print("Reversed List:")
print_list(head)
