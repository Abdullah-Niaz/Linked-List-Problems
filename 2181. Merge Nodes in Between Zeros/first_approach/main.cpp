#include <iostream>
#include <chrono>
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

// Solution class with mergeNodes function
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *p1 = head->next;
        ListNode *p2 = p1;

        while (p2 != NULL)
        {
            int sum = 0;
            while (p2 != NULL && p2->val != 0)
            {
                sum += p2->val;
                p2 = p2->next;
            }
            p1->val = sum;
            p2 = p2->next;
            p1->next = p2;
            p1 = p1->next;
        }
        return head->next;
    }
};

// Helper function to create a linked list from an array
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
    // Input array to simulate the linked list values
    int arr[] = {0, 3, 1, 0, 4, 5, 2, 0}; // Example list
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createList(arr, size);

    Solution sol;

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    ListNode *result = sol.mergeNodes(head);

    // Stop measuring time and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Merged List: ";
    printList(result);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
