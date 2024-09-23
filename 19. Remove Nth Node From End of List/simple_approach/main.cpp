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
    int travel_front(ListNode *head)
    {
        int length = 0;
        while (head != nullptr)
        {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int L = travel_front(head);

        if (n == L)
        {
            ListNode *temp = head->next;
            delete head;
            return temp;
        }

        int steps = L - n;
        ListNode *temp = head;
        ListNode *prev = nullptr;

        while (steps--)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
        return head;
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
