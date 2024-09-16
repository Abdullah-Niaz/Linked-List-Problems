#include <iostream>

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
    int findLength(ListNode *head)
    {
        int l = 0;
        while (head != nullptr)
        {
            l++;
            head = head->next;
        }
        return l;
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        int L = findLength(head);

        // Find the k-th node from the start
        ListNode *Node1 = head;
        for (int i = 1; i < k; i++)
        {
            Node1 = Node1->next;
        }

        // Find the k-th node from the end
        ListNode *Node2 = head;
        for (int i = 1; i < L - k + 1; i++)
        {
            Node2 = Node2->next;
        }

        // Swap the values of Node1 and Node2
        std::swap(Node1->val, Node2->val);
        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Utility function to create a linked list from an array
ListNode *createList(int arr[], int n)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main()
{
    Solution solution;

    // Example list: 1 -> 2 -> 3 -> 4 -> 5
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createList(arr, n);
    std::cout << "Original List: ";
    printList(head);

    int k = 2; // Example input k
    head = solution.swapNodes(head, k);

    std::cout << "List after swapping: ";
    printList(head);

    return 0;
}
