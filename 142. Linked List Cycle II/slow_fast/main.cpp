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
    ListNode *detectCycle(ListNode *head)
    {
        // Edge case: if the list is empty or has only one node
        if (!head || !head->next)
        {
            return NULL;
        }

        ListNode *slow = head, *fast = head;

        // Move slow by 1 step and fast by 2 steps to detect a cycle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, there's a cycle
            if (slow == fast)
            {
                break;
            }
        }

        // If no cycle, return NULL
        if (slow != fast)
        {
            return NULL;
        }

        // Move one pointer to the head, both pointers move one step at a time
        ListNode *p = head;
        while (p != slow)
        {
            p = p->next;
            slow = slow->next;
        }

        // Both pointers meet at the start of the cycle
        return p;
    }
};

// Example usage
int main()
{
    // Create a linked list with a cycle
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node0 = new ListNode(0);
    ListNode *node_neg4 = new ListNode(-4);

    head->next = node2;
    node2->next = node0;
    node0->next = node_neg4;
    node_neg4->next = node2; // Creates a cycle

    Solution solution;
    ListNode *result = solution.detectCycle(head);

    if (result != NULL)
    {
        cout << "Cycle starts at node with value: " << result->val << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    return 0;
}
