#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class to delete a node
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            return; // Can't delete the last node this way
        }

        // Copy the next node's value into the current node
        node->val = node->next->val;

        // Store the node to be deleted
        ListNode *temp = node->next;

        // Bypass the next node
        node->next = node->next->next;

        // Free memory for the deleted node
        delete temp;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Create a linked list: 4 -> 5 -> 1 -> 9 -> NULL
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Delete node with value 5
    Solution().deleteNode(head->next);

    // Print modified list
    cout << "List after deleting node 5: ";
    printList(head);

    // Free memory for the remaining list
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}