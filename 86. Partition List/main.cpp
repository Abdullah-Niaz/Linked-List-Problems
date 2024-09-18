#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class to partition the list
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(0); // Dummy node for the 'small' list
        ListNode *large = new ListNode(0); // Dummy node for the 'large' list

        ListNode *smallP = small; // Pointer to track the 'small' list
        ListNode *largeP = large; // Pointer to track the 'large' list

        // Traverse the original list
        while (head != nullptr)
        {
            if (head->val < x)
            {
                smallP->next = head;
                smallP = smallP->next;
            }
            else
            {
                largeP->next = head;
                largeP = largeP->next;
            }
            head = head->next;
        }

        // Connect the 'small' list to the 'large' list
        smallP->next = large->next;
        // End the 'large' list
        largeP->next = nullptr;

        // Return the head of the new partitioned list
        return small->next;
    }
};

// Helper function to create a linked list from an array of values
ListNode *createLinkedList(initializer_list<int> values)
{
    if (values.size() == 0)
        return nullptr;
    auto it = values.begin();
    ListNode *head = new ListNode(*it);
    ListNode *current = head;
    ++it;
    while (it != values.end())
    {
        current->next = new ListNode(*it);
        current = current->next;
        ++it;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    Solution solution;

    // Test case: [1, 4, 3, 2, 5, 2], partition around x = 3
    ListNode *head = createLinkedList({1, 4, 3, 2, 5, 2});

    cout << "Original List: ";
    printLinkedList(head);

    // Partition the list with x = 3
    head = solution.partition(head, 3);

    cout << "Partitioned List: ";
    printLinkedList(head);

    return 0;
}
