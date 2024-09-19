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
    ListNode *reverseLL(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *last = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        int sum = 0;
        int carry = 0;
        ListNode *ans = new ListNode();
        ListNode *current = ans;

        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            current->val = sum % 10;
            carry = sum / 10;
            ListNode *newNode = new ListNode(carry);
            newNode->next = current;
            current = newNode;
            sum = carry;
        }

        return carry == 0 ? current->next : current;
    }
};

// Helper functions to create and print a linked list.
ListNode *createList(std::initializer_list<int> vals)
{
    ListNode *head = new ListNode();
    ListNode *current = head;
    for (int val : vals)
    {
        current->next = new ListNode(val);
        current = current->next;
    }
    return head->next;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    // Create two linked lists
    ListNode *l1 = createList({7, 2, 4, 3});
    ListNode *l2 = createList({5, 6, 4});

    // Add the two numbers
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Print the result
    printList(result);

    return 0;
}
