#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    int arr[] = {1, 2, 3, 4, 5}; // Sample array
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createLinkedList(arr, n);

    Solution solution;
    ListNode *middleNode = solution.middleNode(head);

    printLinkedList(middleNode); // This will print the second half starting from the middle

    return 0;
}