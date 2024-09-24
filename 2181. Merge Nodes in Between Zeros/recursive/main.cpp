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
    ListNode *mergeNodes(ListNode *head)
    {
        // Move past the initial zero node
        head = head->next;

        if (head == nullptr)
        {
            return head; // If the list is empty after the first zero, return NULL
        }

        ListNode *temp = head;
        int sum = 0;

        // Traverse through the list and sum the values between two zeros
        while (temp != nullptr && temp->val != 0)
        {
            sum += temp->val;
            temp = temp->next;
        }

        // Update the value of the current node to the sum
        head->val = sum;

        // Recursively merge the rest of the list after the zero
        head->next = mergeNodes(temp);

        return head;
    }
};

// Helper function to create a linked list from an array of values
ListNode *createList(int arr[], int size)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    for (int i = 0; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return dummy;
}

// Helper function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Input array to simulate the linked list
    int arr[] = {0, 3, 1, 0, 4, 5, 2, 0}; // Example input
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    ListNode *head = createList(arr, size);

    Solution sol;

    // Call mergeNodes and print the merged list
    ListNode *result = sol.mergeNodes(head);

    cout << "Merged List: ";
    printList(result);

    return 0;
}
