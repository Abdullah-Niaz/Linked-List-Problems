#include <iostream>
#include <set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Brute Force 
        set<ListNode*> visited;  // Set to store visited nodes
        ListNode *curr = head;
        
        // Traverse the list
        while (curr != NULL) {
            // If current node is already in the set, cycle is found
            if (visited.find(curr) != visited.end()) {
                return curr;
            }
            // Add current node to the visited set
            visited.insert(curr);
            // Move to the next node
            curr = curr->next;
        }
        
        // No cycle found, return NULL
        return NULL;
    }
};

// Example usage
int main() {
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
    
    if (result != NULL) {
        cout << "Cycle starts at node with value: " << result->val << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
