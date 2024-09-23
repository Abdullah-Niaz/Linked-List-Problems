#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0); // Use a dummy node to handle edge cases.
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;

        // Move the 'first' pointer n+1 steps ahead.
        for (int i = 0; i <= n; i++)
        {
            first = first->next;
        }

        // Move both 'first' and 'second' pointers until 'first' reaches the end.
        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }

        // 'second' is now at the node before the one to remove.
        ListNode *deleteNode = second->next;
        second->next = second->next->next; // Remove the nth node from the end.
        delete deleteNode;                 // Free the memory.

        ListNode *result = dummy->next;
        delete dummy; // Clean up the dummy node.
        return result;
    }
};

// Utility function to print the linked list
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Helper function to create a list from array
ListNode *createList(int arr[], int size)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < size; i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    Solution solution;

    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode *head = createList(arr, 5);

    cout << "Original List: ";
    printList(head);

    head = solution.removeNthFromEnd(head, n);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
