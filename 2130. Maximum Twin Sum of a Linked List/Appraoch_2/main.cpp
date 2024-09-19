#include <iostream>
#include <stack>
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
        // Step 1: Use a stack to store node values
        stack<int> st;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            st.push(curr->val);
            curr = curr->next;
        }

        // Step 2: Find the maximum pair sum
        int N = st.size();
        curr = head;
        int count = 1;
        int result = 0;
        while (count <= N / 2)
        {
            result = max(result, curr->val + st.top());
            st.pop();
            curr = curr->next;
            count++;
        }
        return result;
    }
};

int main()
{
    ListNode *head = nullptr;
    Solution sol;

    // Sample input
    int nodes[] = {4, 2, 6, 1};
    int n = sizeof(nodes) / sizeof(nodes[0]);

    for (int i = 0; i < n; i++)
    {
        appendNode(head, nodes[i]);
    }

    // Calculate and print the result
    int result = sol.pairSum(head);
    cout << "Maximum pair sum: " << result << endl;

    return 0;
}
