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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *left = list1;
        ListNode *right = list1;

        // Traverse to find left (node at a-1) and right (node at b+1)
        for (int i = 0; i <= b; i++)
        {
            if (i == a - 1)
            {
                left = right;
            }
            right = right->next;
        }

        // Connect left's next to the head of list2
        left->next = list2;

        // Traverse to the end of list2
        ListNode *temp = list2;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        // Connect the end of list2 to right (node after b)
        temp->next = right;

        return list1;
    }
};

// Helper function to create a linked list from an array
ListNode *createLinkedList(int arr[], int size)
{
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    for (int i = 0; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main()
{
    // Test case 1
    int list1Arr[] = {0, 1, 2, 3, 4, 5, 6};
    int list2Arr[] = {1000000, 1000001, 1000002, 1000003, 1000004};
    int a = 2, b = 5;

    // Create linked lists from arrays
    ListNode *list1 = createLinkedList(list1Arr, 7);
    ListNode *list2 = createLinkedList(list2Arr, 5);

    // Print initial lists
    cout << "List 1: ";
    printLinkedList(list1);
    cout << "List 2: ";
    printLinkedList(list2);

    // Merge lists using Solution class
    Solution solution;
    ListNode *mergedList = solution.mergeInBetween(list1, a, b, list2);

    // Print the merged list
    cout << "Merged List: ";
    printLinkedList(mergedList);

    return 0;
}
