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

// Function to add a node at the end of the list
void appendNode(ListNode *&head, int val)
{
    if (head == nullptr)
    {
        head = new ListNode(val);
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new ListNode(val);
    }
}

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> vec;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }

        int result = 0;
        int i = 0, j = vec.size() - 1;
        while (i < j)
        {
            result = max(result, vec[i] + vec[j]);
            i++;
            j--;
        }
        return result;
    }
};

int main()
{
    ListNode *head = nullptr;
    Solution sol;

    // Sample input
    vector<int> nodes = {4, 2, 6, 1};
    for (int val : nodes)
    {
        appendNode(head, val);
    }

    // Calculate and print the result
    int result = sol.pairSum(head);
    cout << "Maximum pair sum: " << result << endl;

    return 0;
}
