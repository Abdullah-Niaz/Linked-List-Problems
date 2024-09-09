#include <iostream>
#include <vector>
#include <unordered_set>

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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> st(nums.begin(), nums.end());

        // Remove nodes from the start of the list that match the set values
        while (head != NULL && st.find(head->val) != st.end())
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        // Traverse through the remaining list and remove matching nodes
        ListNode *curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            if (st.find(curr->next->val) != st.end())
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Create a linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    vector<int> listValues = {1, 2, 6, 3, 4, 5, 6};
    ListNode *head = createLinkedList(listValues);

    // Vector with values to remove: 6
    vector<int> valuesToRemove = {6};

    // Modify the list
    ListNode *modifiedHead = solution.modifiedList(valuesToRemove, head);

    // Print the modified list
    cout << "Modified list: ";
    printList(modifiedHead);

    // Clean up memory
    while (modifiedHead)
    {
        ListNode *temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0;
}
