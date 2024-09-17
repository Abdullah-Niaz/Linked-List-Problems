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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};

// Helper function to create a linked list from an array of values
ListNode *createLinkedList(std::initializer_list<int> values)
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
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main()
{
    Solution solution;

    // Test case: [1, 2, 3, 4]
    ListNode *head = createLinkedList({1, 2, 3, 4});

    std::cout << "Original List: ";
    printLinkedList(head);

    head = solution.swapPairs(head);

    std::cout << "Swapped List: ";
    printLinkedList(head);

    return 0;
}
