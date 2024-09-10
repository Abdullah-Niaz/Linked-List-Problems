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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Initialize pointers for odd and even lists
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        // Rearrange nodes
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        // Connect the end of the odd list to the head of the even list
        odd->next = evenHead;

        return head;
    }
};

// Helper function to create a linked list from an array
ListNode *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < n; ++i)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list from a given node
void printLinkedList(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->val;
        if (node->next != NULL)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}; // Sample input
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    ListNode *head = createLinkedList(arr, n);

    // Apply the oddEvenList transformation
    Solution solution;
    ListNode *result = solution.oddEvenList(head);

    // Print the result
    printLinkedList(result);

    return 0;
}
