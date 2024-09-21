#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class that contains the method to reverse the sublist.
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // Edge cases: if the list is empty or has only one node.
        if (!head || !head->next)
            return head;

        // Create a dummy node to simplify the reversal process.
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // prev points to the node just before the 'left' position.
        ListNode *prev = dummy;
        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        // curr is the node at the 'left' position.
        ListNode *curr = prev->next;

        // Reverse the sublist from 'left' to 'right'.
        for (int i = 1; i <= right - left; i++)
        {
            ListNode *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }

        // Return the new head of the list (dummy->next).
        ListNode *new_head = dummy->next;
        delete dummy; // Free the allocated memory for dummy node.
        return new_head;
    }
};

// Helper function to create a linked list from an array.
ListNode *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list.
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    // Example: reverse the sublist from position 2 to 4 in the linked list [1, 2, 3, 4, 5]
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list from the array
    ListNode *head = createLinkedList(arr, n);

    cout << "Original List:" << endl;
    printList(head);

    Solution solution;
    // Reverse the sublist from position 2 to 4
    ListNode *new_head = solution.reverseBetween(head, 2, 4);

    cout << "\nReversed Sublist (from position 2 to 4):" << endl;
    printList(new_head);

    return 0;
}
