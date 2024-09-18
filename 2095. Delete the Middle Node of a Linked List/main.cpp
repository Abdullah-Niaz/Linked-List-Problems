#include <iostream>
#include <vector>
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
    ListNode *deleteMiddle(ListNode *head)
    {
        // If the list is empty or has only one node, return NULL
        if (!head || !head->next)
        {
            return NULL;
        }

        // Initialize slow pointer to the head
        ListNode *slow = head;
        // Initialize fast pointer two nodes ahead
        ListNode *fast = head->next->next;

        // Traverse the list with slow and fast pointers
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow pointer is now at the node just before the middle node
        // Delete the middle node
        ListNode *middle = slow->next;
        slow->next = slow->next->next;
        delete middle;

        // Return the modified list head
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Main function to test the deleteMiddle function
int main()
{
    Solution solution;

    // Test case: Linked list [1, 2, 3, 4, 5]
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createList(values);
    cout << "Original list: ";
    printList(head);

    head = solution.deleteMiddle(head);
    cout << "After deleting middle: ";
    printList(head);

    return 0;
}
