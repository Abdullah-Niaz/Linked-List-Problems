#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        // Create a dummy node to handle cases where the head is part of the zero-sum sequence
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // Hash map to store the first occurrence of each prefix sum
        unordered_map<int, ListNode *> prefix_sum_map;

        // First pass: calculate the prefix sums and store the last occurrence of each sum
        int prefix_sum = 0;
        ListNode *curr = dummy;
        while (curr)
        {
            prefix_sum += curr->val;
            prefix_sum_map[prefix_sum] = curr;
            curr = curr->next;
        }

        // Second pass: remove the zero-sum subsequences
        prefix_sum = 0;
        curr = dummy;
        while (curr)
        {
            prefix_sum += curr->val;
            curr->next = prefix_sum_map[prefix_sum]->next; // Skip nodes summing to zero
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode *createLinkedList(const vector<int> &values)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    for (int value : values)
    {
        curr->next = new ListNode(value);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    ListNode *curr = head;
    vector<int> result;
    while (curr)
    {
        result.push_back(curr->val);
        curr = curr->next;
    }

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    // Test case: input list
    vector<int> input_list = {1, 2, -3, 3, 1};

    // Create linked list from input
    ListNode *head = createLinkedList(input_list);

    // Create solution instance
    Solution sol;

    // Remove zero-sum sublists
    ListNode *result_head = sol.removeZeroSumSublists(head);

    // Print the result
    printLinkedList(result_head);

    return 0;
}
