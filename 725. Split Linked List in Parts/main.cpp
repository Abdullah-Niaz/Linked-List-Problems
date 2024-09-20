#include <iostream>
#include <vector>
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // Find the length of the linked list
        ListNode *curr = head;
        int L = 0;
        while (curr)
        {
            L++;
            curr = curr->next;
        }

        // Calculate the number of nodes in each part and the remainder
        int eachBucketNodes = L / k;
        int remainderNodes = L % k;

        vector<ListNode *> result(k, NULL);
        curr = head;
        ListNode *prev = NULL;

        // Split the list into k parts
        for (int i = 0; i < k && curr != NULL; i++)
        {
            result[i] = curr;

            int partSize = eachBucketNodes + (remainderNodes > 0 ? 1 : 0);

            for (int count = 1; count < partSize; count++)
            {
                curr = curr->next;
            }

            if (curr != NULL)
            {
                ListNode *nextPart = curr->next;
                curr->next = NULL;
                curr = nextPart;
            }

            remainderNodes--;
        }

        return result;
    }
};

// Function to print the linked list parts
void printParts(const vector<ListNode *> &parts)
{
    for (int i = 0; i < parts.size(); i++)
    {
        ListNode *curr = parts[i];
        cout << "Part " << i + 1 << ": ";
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

// Helper function to create a linked list from a vector
ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *curr = head;
    for (int i = 1; i < values.size(); i++)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    Solution solution;

    // Create a sample linked list
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createList(values);
    int k = 3;

    // Split the linked list into parts
    vector<ListNode *> parts = solution.splitListToParts(head, k);

    // Print the split parts
    printParts(parts);

    return 0;
}
